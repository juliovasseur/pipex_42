/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:17:06 by marvin            #+#    #+#             */
/*   Updated: 2022/11/09 02:17:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr1(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_callocgnl(size_t c, size_t size)
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

char	*ft_strjoingnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen1(const char *c)
{
	unsigned int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
