/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:59:00 by jules             #+#    #+#             */
/*   Updated: 2023/03/31 18:13:04 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	get_fd_infile(char **argv, t_pipex *pipex)
{
	pipex->idx = 0;
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		pipex->idx = 1;
		perror("ERR_INFILE");
	}
}

void	get_fd_outfile(char *argv, t_pipex *pipex)
{
	pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		perror("ERR_OUTFILE");
}
