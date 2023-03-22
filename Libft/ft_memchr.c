/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:46:57 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/05 15:09:50 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	if (!s)
		return (0);
	str = (unsigned char *) s;
	while (n)
	{
		if (*str == (unsigned char) c)
			return ((void *)str);
		n--;
		str++;
	}
	return (0);
}
