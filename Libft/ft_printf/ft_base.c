/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:22:05 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/28 15:00:30 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{	
		if (base[i] < 32 || base[i] > 126 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_base(unsigned int nbr, char *base)
{
	long int	nbtemp;
	long int	i;
	int			ct;

	ct = 0;
	i = 0;
	if (check(base) == 0)
		return (0);
	nbtemp = 0;
	while (base[i])
		i++;
	if (nbr < i)
		ct += ft_putchar(base[nbr % i]);
	else
	{
		ct += ft_base(nbr / i, base);
		nbtemp = nbr % i;
		ct += ft_putchar(base[nbtemp]);
	}
	return (ct);
}
