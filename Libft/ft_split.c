/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:07 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/08 17:18:52 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clearsplit(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return ;
}

static int	ft_len_word(char const *s, char c)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			cpt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cpt);
}

static void	ft_len_inword(char const *s, char c, char **str, int i)
{
	int	j;
	int	start;
	int	len;

	j = 0;
	while (j < ft_len_word(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		len = 0;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		str[j] = ft_substr(s, start, len);
		if (!str[j])
		{
			ft_clearsplit(str, j);
			return ;
		}
		j++;
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**dst;

	if (!s)
		return (NULL);
	k = ft_len_word(s, c);
	dst = malloc(sizeof(char *) * (k + 1));
	if (!dst)
		return (NULL);
	dst[k] = NULL;
	ft_len_inword(s, c, dst, 0);
	return (dst);
}
