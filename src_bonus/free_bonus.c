/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:36 by jules             #+#    #+#             */
/*   Updated: 2023/03/23 11:27:50 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pipex_bonus.h"


void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->tab_paths[i])
	{
		free(pipex->tab_paths[i]);
		i++;
	}
	free(pipex->tab_paths);
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
	while (pipex->tab_paths[i])
	{
		free(pipex->tab_paths[i]);
		i++;
	}
	free(pipex->tab_paths);
	free(pipex->tab_cmd);
	free(pipex->cmd);
}

void	pipe_free(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free(pipex->pipe);
	msg("ERR_ENVP");
	exit(1);
}
