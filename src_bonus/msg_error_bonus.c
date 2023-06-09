/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:55 by jules             #+#    #+#             */
/*   Updated: 2023/03/28 13:40:36 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	return (1);
}

void	msg_pipe(void)
{
	write(2, "ERROR_CMD", ft_strlen("ERROR_CMD"));
	write(2, "\n", 1);
}

void	msg_send_error(char *err)
{
	perror(err);
	exit(1);
}
