/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:03:27 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/06 18:44:22 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t c, size_t size)
{
	char	*str;
	size_t	i;

	if (c == 0)
	{
		str = malloc(0);
		if (!str)
			return (NULL);
		return (str);
	}
	if (c * size / c != size)
		return (NULL);
	i = 0;
	str = malloc(c * size);
	if (!str)
		return (0);
	while (i < c * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
