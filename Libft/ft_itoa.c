/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:08:31 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/05 15:10:01 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_int(long long int nb)
{
	long long int	cpt;

	cpt = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb == INT_MIN)
	{
		return (11);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		cpt++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		cpt++;
	}
	return (cpt);
}

char	*ft_itoa(int nb)
{
	char			*str;
	long long int	n;
	long int		len;

	n = nb;
	len = ft_len_int(n);
	str = malloc(ft_len_int(n) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[len] = '\0';
	len--;
	while (n > 9)
	{
		str[len] = 48 + (n % 10);
		n = n / 10;
		len--;
	}
	str[len] = 48 + (n % 10);
	return (str);
}
