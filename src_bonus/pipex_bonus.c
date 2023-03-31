/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:59:05 by jules             #+#    #+#             */
/*   Updated: 2023/03/31 15:38:51 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	close_all_pipes(t_pipex *pipex)
{
	if (pipex->pipe[0][0] != -1)
		close(pipex->pipe[0][0]);
	if (pipex->pipe[0][1] != -1)
		close(pipex->pipe[0][1]);
	if (pipex->pipe[1][0])
		close(pipex->pipe[1][0]);
	if (pipex->pipe[1][1])
		close(pipex->pipe[1][1]);
}

char	*find_path(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

void	add_cmd_slash(char **paths, t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		if (!paths[i])
		{
			close_all_pipes(pipex);
			parent_free(pipex);
			exit (1);
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
}

void tab_wait(t_pipex *pipex)
{
	int i;

	i = 0;
	if (pipex->infile == -1)
		i++;
	if (pipex->outfile == -1)
		i++;
	pipex->tab_wait = malloc(sizeof(int) * (pipex->nb_cmd - i));
}

void	wait_tab(t_pipex *pipex)
{
	int	i;
	int j;

	j = 0;
	if (pipex->infile == -1)
		j++;
	if (pipex->outfile == -1)
		j++;
	i = 0;
	while (i < pipex->nb_cmd - j)
	{
		waitpid(pipex->tab_wait[i], NULL, 0);
		i++;
	}
	free(pipex->tab_wait);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (0);
	if (verif_all_and_get_file(argc, argv, pipex) == 0)
		return (0);
	pipex->nb_cmd = argc - 3 - pipex->here_doc;
	pipex->env_path = find_path(envp);
	if (!pipex->env_path)
	{
		pipex->tab_paths = NULL;
		pipex->idx_path = 0;
		msg("ERR INVALID PATH");
	}
	else
	{
		pipex->idx_path = 1;
		pipex->tab_paths = ft_split(pipex->env_path, ':');
		if (!pipex->tab_paths)
			pipe_free(pipex);
		add_cmd_slash(pipex->tab_paths, pipex);
	}
	pipe(pipex->pipe[0]);
	pipe(pipex->pipe[1]);
	get_fd_infile(argv, pipex);
	get_fd_outfile(argv[argc - 1], pipex);
	tab_wait(pipex);
	pipex->tmp_tab = 0;
	if (pipex->outfile == -1)
	{
		while ((pipex->idx) < pipex->nb_cmd - 1)
		{
			child(pipex, argv, envp);
			pipex->idx++;
		}
	}
	else 
	{
		while ((pipex->idx) < pipex->nb_cmd)
		{
			child(pipex, argv, envp);
			pipex->idx++;
		}
	}
	close_all_pipes(pipex);
	wait_tab(pipex);
	parent_free(pipex);
	return (0);
}
