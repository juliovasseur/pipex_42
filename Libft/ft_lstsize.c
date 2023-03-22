/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:35:44 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/05 15:09:52 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cpt;

	cpt = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		cpt++;
	}
	return (cpt);
}
