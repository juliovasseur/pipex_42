/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:12:44 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/31 18:38:36 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	verif_all_and_get_file(int argc, t_pipex *pipex)
{
	if (argc != 5)
	{
		free(pipex);
		msg("ERR_INPUT");
		return (0);
	}
	return (1);
}

int	verif_argv(char *argv)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (argv[j])
	{
		if (argv[j] != 32 && argv[j] != '\t')
			k++;
		j++;
	}
	if (k == 0)
		return (0);
	return (1);
}

void	double_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}
