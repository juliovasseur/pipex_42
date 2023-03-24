/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_error_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:35:00 by jules             #+#    #+#             */
/*   Updated: 2023/03/24 15:26:54 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_all(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->file_input);
	close(pipex->file_output);
	while (pipex->tab_path[i])
	{
		free(pipex->tab_path[i]);
		i++;
	}
	free(pipex->tab_path);
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

int	open_file_and_verif(t_pipex *pipex, char **argv)
{
	if (!pipex)
		return (0);
	if (verif_argv(argv) == 0)
	{
		free(pipex);
		msg_write_error("ERR_ARG");
		return (0);
	}
	pipex->file_input = open(argv[1], O_RDONLY);
	if (pipex->file_input == -1)
	{
		free(pipex);
		msg_send_error("Error file input");
		return (0);
	}
	pipex->file_output = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pipex->file_output == -1)
	{
		free(pipex);
		msg_send_error("Error file output");
		return (0);
	}
	return (1);
}

int	msg_write_error(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	return (1);
}

void	msg_send_error(char *err)
{
	perror(err);
	exit (1);
}
