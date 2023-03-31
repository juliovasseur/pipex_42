/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:41 by jules             #+#    #+#             */
/*   Updated: 2023/03/31 16:04:10 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	free_malloc_error(void)
{
	perror("Error malloc");
	exit (1);
}

static char	*get_cmd(char **path, char *command)
{
	int		i;
	char	*cmd;

	i = 0;
	while (path[i])
	{
		cmd = ft_strjoin(path[i], command);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

static char	*get_cmd_two(char *command)
{
	if (access(command, 0) == 0)
		return (command);
	else
		return (NULL);
}

static void	double_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

static void	free_error_malloc(t_pipex *pipex)
{
	msg_pipe();
	child_free(pipex);
	free(pipex->tab_wait);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	close(0);
	close(1);
	free(pipex);
	exit(1);
}


static void	free_error_malloc_two(t_pipex *pipex)
{
	child_free(pipex);
	free(pipex->tab_wait);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	close(0);
	close(1);
	free(pipex);
	exit(1);
}


int	verif_argv(char *argv)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (argv[j])
	{
			if (argv[j] != 32 && argv[j] != '\t')
				k++;
			j++;
	}
	if (k == 0)
		return (0);
	return (1);
}

void	free_error_cmd(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->tab_paths != NULL)
	{
		while (pipex->tab_paths[i])
		{
			free(pipex->tab_paths[i]);
				i++;
		}
		free(pipex->tab_paths);
	}
	msg_pipe();
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	close(0);
	close(1);
	free(pipex->tab_wait);
	free(pipex);
	exit(1);
}

void	child(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->pipe[(pipex->idx) % 2][0]);
	close(pipex->pipe[pipex->idx % 2][1]);
	pipe(pipex->pipe[pipex->idx % 2]);
	pipex->pid = fork();

	if (pipex->pid == 0)
	{
		if (pipex->idx == 0)
			double_dup2(pipex->infile, pipex->pipe[0][1]);
		else if (pipex->idx == pipex->nb_cmd - 1)
			double_dup2(pipex->pipe[(pipex->idx - 1) % 2][0], pipex->outfile);
		else 
			double_dup2(pipex->pipe[(pipex->idx - 1) % 2][0], pipex->pipe[pipex->idx % 2][1]);
		close_all_pipes(pipex);
		if (verif_argv(argv[2 + pipex->here_doc + pipex->idx]) == 0)
			free_error_cmd(pipex);
		pipex->tab_cmd = ft_split(argv[2 + pipex->here_doc + pipex->idx], ' ');
		if (!pipex->tab_cmd)
			free_malloc_error();
		if (pipex->idx_path == 1)
			pipex->cmd = get_cmd(pipex->tab_paths, pipex->tab_cmd[0]);
		else
			pipex->cmd = get_cmd_two(pipex->tab_cmd[0]);
		if (pipex->cmd == NULL)
			free_error_malloc(pipex);
		if (execve(pipex->cmd, pipex->tab_cmd, envp) == -1)
		{
			perror("Error with execve");
			free_error_malloc_two(pipex);
			free(pipex->cmd);
			exit (1);
		}
	}
	pipex->tab_wait[pipex->tmp_tab++] = pipex->pid;
}
