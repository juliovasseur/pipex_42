/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:41 by jules             #+#    #+#             */
/*   Updated: 2023/03/31 18:39:34 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

static void	exec_dup2(t_pipex *pipex)
{
	if (pipex->idx == 0)
		double_dup2(pipex->infile, pipex->pipe[0][1]);
	else if (pipex->idx == pipex->nb_cmd - 1)
		double_dup2(pipex->pipe[(pipex->idx - 1) % 2][0], pipex->outfile);
	else
		double_dup2(pipex->pipe[(pipex->idx - 1) % 2][0],
			pipex->pipe[pipex->idx % 2][1]);
}

static void	verif_absolute_road(t_pipex *pipex)
{
	pipex->cmd = get_cmd(pipex->tab_paths, pipex->tab_cmd[0]);
	if (pipex->cmd == NULL)
	{
		pipex->cmd = get_cmd_two(pipex->tab_cmd[0]);
		if (pipex->cmd == NULL)
			free_error_malloc(pipex);
	}
}

void	child(t_pipex *pipex, char **argv, char **envp)
{
	close_before(pipex);
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		exec_dup2(pipex);
		close_all_pipes(pipex);
		if (verif_argv(argv[2 + pipex->idx]) == 0)
			free_error_cmd(pipex);
		pipex->tab_cmd = ft_split(argv[2 + pipex->idx], ' ');
		if (!pipex->tab_cmd)
			free_malloc_error();
		if (pipex->idx_path == 1)
			verif_absolute_road(pipex);
		else
			pipex->cmd = get_cmd_two(pipex->tab_cmd[0]);
		if (pipex->cmd == NULL)
			free_error_malloc(pipex);
		if (execve(pipex->cmd, pipex->tab_cmd, envp) == -1)
			free_error_execve(pipex);
	}
	pipex->tab_wait[pipex->tmp_tab++] = pipex->pid;
}
