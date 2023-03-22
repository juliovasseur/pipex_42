/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:29:05 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/02 19:01:56 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	maxmin_int(long int nb, int sign)
{
	if (nb * sign > INT_MAX)
		return (-1);
	return (0);
}

int	ft_atoi(const char*str)
{
	int			i;
	int			sign;
	long int	nb;
	int			k;

	sign = 1;
	nb = 0;
	i = 0;
	k = maxmin_int(nb, sign);
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (k);
		i++;
	}	
	return (nb * sign);
}

int	ft_atol(const char*str)
{
	int			i;
	int			sign;
	long int	nb;

	sign = 1;
	nb = 0;
	i = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (1000);
		i++;
	}	
	return (nb * sign);
}
