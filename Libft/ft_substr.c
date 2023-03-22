/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:50:22 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/05 15:10:20 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		size;
	char	*str;

	if (!s)
		return (NULL);
	size = ft_strlen(s) - start;
	if (size < 0)
		size = 0;
	if ((size_t)size > len)
		size = len;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	size--;
	while (size >= 0)
	{
		str[size] = s[start + size];
		size--;
	}
	return (str);
}
