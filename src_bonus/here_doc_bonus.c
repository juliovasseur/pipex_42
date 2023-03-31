/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:46 by jules             #+#    #+#             */
/*   Updated: 2023/03/29 11:19:22 by jvasseur         ###   ########.fr       */
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

void	here_doc(t_pipex *pipex, char *argv)
{
	char	*str;
	char	*tmp;

	pipe(pipex->tube);
	tmp = argv;
	argv = ft_strjoin(tmp, "\n");
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if ((ft_strncmp(argv, str, ft_strlen(argv) + 1) == 0))
			break ;
		ft_putstr_fd(str, pipex->tube[1]);
		free(str);
	}
	free(argv);
	free(str);
	close(pipex->tube[1]);
}
