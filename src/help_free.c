/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:52:25 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/31 17:54:37 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

void	free_malloc_error(void)
{
	perror("Error malloc");
	exit (1);
}

void	free_error_malloc(t_pipex *pipex)
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

void	free_error_malloc_two(t_pipex *pipex)
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
