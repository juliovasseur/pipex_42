/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:59:00 by jules             #+#    #+#             */
/*   Updated: 2023/03/31 13:08:12 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	get_fd_infile(char **argv, t_pipex *pipex)
{
	pipex->idx = 0;
	if (!ft_strncmp("here_doc", argv[1], 9))
	{
		here_doc(pipex, argv[2]);
		pipe(&pipex->tube[0]);
		pipex->infile = pipex->tube[0];
	}
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
		{
			pipex->idx = 1;
			perror("ERR_INFILE");
		}
	}
}

void	get_fd_outfile(char *argv, t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		perror("ERR_OUTFILE");
	}
}

int	verif_all_and_get_file(int argc, char **argv, t_pipex *pipex)
{
	if (argc < here_doc_or_not(argv[1], pipex))
	{
		free(pipex);
		msg("ERR_INPUT");
		return (0);
	}
	return (1);
}
