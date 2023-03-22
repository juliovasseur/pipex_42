/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:08:49 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/02 17:01:54 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check2(char *base)
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

int	ft_putnbr_base2(unsigned long nbr, char *base)
{
	long int nbtemp;
	unsigned long i;
	int ct;

	ct = 0;
	i = 0;
	if (check2(base) == 0)
		return (0);
	nbtemp = 0;
	while (base[i])
		i++;
	if (nbr < i)
		ct += ft_putchar(base[nbr % i]);
	else
	{
		ct += ft_putnbr_base2(nbr / i, base);
		nbtemp = nbr % i;
		ct += ft_putchar(base[nbtemp]);
	}
	return (ct);
}

int	ft_printaddress(void *nb)
{
    int ct;
    unsigned long long nbr;

    ct = 0;
    nbr = (unsigned long long) nb;
	if ( nbr == 0)
        ct += write(1, "(nil)" , 5);
    else 
    {
        ct += write(1, "0x", 2);
        ct += ft_putnbr_base2(nbr, "0123456789abcdef");
    }
	return (ct);
}