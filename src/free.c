/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:36 by jules             #+#    #+#             */
/*   Updated: 2023/03/31 18:34:22 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	if (pipex->tab_paths != NULL)
	{
		while (pipex->tab_paths[i])
		{
			free(pipex->tab_paths[i]);
			i++;
		}
		free(pipex->tab_paths);
	}
	free(pipex);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->tab_cmd[i])
	{
		free(pipex->tab_cmd[i]);
		i++;
	}
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
	free(pipex->tab_cmd);
}

void	pipe_free(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free(pipex->pipe);
	free(pipex);
	msg("Error envp");
	exit(1);
}

void	close_before(t_pipex *pipex)
{
	close(pipex->pipe[(pipex->idx) % 2][0]);
	close(pipex->pipe[pipex->idx % 2][1]);
	pipe(pipex->pipe[pipex->idx % 2]);
}

void	free_error_execve(t_pipex *pipex)
{
	perror("Error with execve");
	free_error_malloc_two(pipex);
	free(pipex->cmd);
	exit (1);
}
