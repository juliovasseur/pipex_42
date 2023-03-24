/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:59:00 by jules             #+#    #+#             */
/*   Updated: 2023/03/24 11:20:46 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	get_fd_infile(char **argv, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
	{
		here_doc(pipex, argv[2]);
		pipex->infile = pipex->tube[0];
	}
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
		{
			free(pipex);
			msg_send_error("ERR_INFILE");
		}
	}
}

void	get_fd_outfile(char *argv, t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		free(pipex);
		msg_send_error("ERR_OUTFILE");
	}
}

int	verif_argv(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (argv[i])
	{
		j = 0;
		k = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != 32 && argv[i][j] != '\t')
				k++;
			j++;
		}
		if (k == 0)
			return (0);
		i++;
	}
	return (1);
}

int	verif_all_and_get_file(int argc, char **argv, t_pipex *pipex)
{
	if (argc < here_doc_or_not(argv[1], pipex))
	{
		free(pipex);
		msg("ERR_INPUT");
		return (0);
	}
	if (verif_argv(argv) == 0)
	{
		free(pipex);
		msg("ERR_ARG");
		return (0);
	}
	get_fd_infile(argv, pipex);
	get_fd_outfile(argv[argc - 1], pipex);
	return (1);
}
