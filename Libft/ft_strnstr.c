/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:56:45 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/05 15:10:25 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (n == 0 && !big)
		return (NULL);
	if (little[i] == '\0')
		return ((char *) big);
	while (big[i] != '\0' && i < n)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < n)
		{
			if (little[j + 1] == '\0')
				return ((char *) &big[i]);
			j++;
		}
		i++;
	}	
	return (NULL);
}		
