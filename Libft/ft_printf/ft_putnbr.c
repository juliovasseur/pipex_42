/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:40:07 by julio             #+#    #+#             */
/*   Updated: 2022/11/28 15:00:36 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long nb)
{
	int	ct;

	ct = 0;
	if (nb < 0)
	{
		ct += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb < 10)
		ct += ft_putchar(nb + 48);
	else
	{
		ct += ft_putnbr(nb / 10);
		ct += ft_putchar(nb % 10 + 48);
	}
	return (ct);
}
