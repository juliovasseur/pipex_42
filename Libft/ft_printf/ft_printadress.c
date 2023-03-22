/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:02:39 by jvasseur          #+#    #+#             */
/*   Updated: 2022/10/20 17:23:02 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	check2(void)
{
	write(1, "2147483648", 10);
}

int	ft_putnbr_base(long long int nbr, char *base, int cpt)
{
	long long int	nbtemp;
	long long int	i;

	i = 0;
	if (check(base) == 0)
		return (1);
	nbtemp = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
			check2();
		else
			nbr = -nbr;
	}
	while (base[i])
		i++;
	if (nbr < i)
        cpt += ft_putchar(base[nbr % i]);
	else
	{
		cpt += ft_putnbr_base(nbr / i, base, cpt);
		nbtemp = nbr % i;
		ft_putchar(base[nbtemp]);
	}
	return (cpt);
}




ft_printaddress(long long int nbr, char *base, int cpt)
{
    cpt += write(1, "0x", 2);
    cpt += ft_putnbr_base(nbr, base, cpt);
}