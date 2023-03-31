/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:59:05 by jules             #+#    #+#             */
/*   Updated: 2023/03/31 18:20:11 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	tab_wait(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->infile == -1)
		i++;
	if (pipex->outfile == -1)
		i++;
	pipex->tab_wait = malloc(sizeof(int) * (pipex->nb_cmd - i));
}

static void	wait_tab(t_pipex *pipex)
{
	int	i;
	int	j;

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

static void	exec_child(t_pipex *pipex, char **argv, char **envp)
{
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
}

static void	verif_path(t_pipex *pipex, char **envp)
{
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
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (0);
	if (verif_all_and_get_file(argc, pipex) == 0)
		return (0);
	pipex->nb_cmd = argc - 3;
	verif_path(pipex, envp);
	pipe(pipex->pipe[0]);
	pipe(pipex->pipe[1]);
	get_fd_infile(argv, pipex);
	get_fd_outfile(argv[argc - 1], pipex);
	tab_wait(pipex);
	pipex->tmp_tab = 0;
	exec_child(pipex, argv, envp);
	close_all_pipes(pipex);
	wait_tab(pipex);
	parent_free(pipex);
	return (0);
}
