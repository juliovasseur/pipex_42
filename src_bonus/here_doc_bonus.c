/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:46 by jules             #+#    #+#             */
/*   Updated: 2023/03/23 15:11:23 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	here_doc_or_not(char *arg, t_pipex *pipex)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	here_doc(char *argv)
{
	char	*str;

	str = get_next_line(0);
	while (1)
	{
		if (str <= 0)
			break ;
		if (strncmp(argv, str, ft_strlen(argv)) == 0)
			break ;
		free(str);
		str = get_next_line(0);
	}
	free(str);
}
