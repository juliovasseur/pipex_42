/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:40:07 by julio             #+#    #+#             */
/*   Updated: 2022/11/28 15:00:37 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr2(unsigned int nb)
{
	int	ct;

	ct = 0;
	if (nb < 10)
		ct += ft_putchar(nb + 48);
	else
	{
		ct += ft_putnbr2(nb / 10);
		ct += ft_putchar(nb % 10 + 48);
	}
	return (ct);
}
