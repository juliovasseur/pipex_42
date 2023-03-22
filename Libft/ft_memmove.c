/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:39:58 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/05 15:09:46 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove( void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;

	if (!dest && !src && n != 0)
		return (NULL);
	i = 0;
	dest2 = (char *) dest;
	src2 = (char *) src;
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			dest2[n] = src2[n];
		}
		return (dest);
	}
	while (i < n)
	{
			dest2[i] = src2[i];
			i++;
	}
	return (dest);
}
