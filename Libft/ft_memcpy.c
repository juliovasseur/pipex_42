/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:38:23 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/05 15:09:47 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	j;
	char	*destcpy;

	if (!dest && !src)
		return (0);
	j = 0;
	destcpy = (char *) dest;
	while (j < n)
	{
		((unsigned char *)destcpy)[j] = ((unsigned char *)src)[j];
		j++;
	}
	return (destcpy);
}
