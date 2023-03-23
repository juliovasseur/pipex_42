/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:59:59 by julio             #+#    #+#             */
/*   Updated: 2022/11/28 15:00:31 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(const char form)
{
	int	ct;

	ct = 0;
	ct += ft_putchar('%');
	ct += ft_putchar(form);
	return (ct);
}

int	ft_form(va_list arg, const char form)
{
	int	ct;

	ct = 0;
	if (form == 'c')
		ct += ft_putchar((char)va_arg(arg, int));
	else if (form == 's')
		ct += ft_putstr(va_arg(arg, char *));
	else if (form == 'd')
		ct += ft_putnbr(va_arg(arg, int));
	else if (form == 'i')
		ct += ft_putnbr(va_arg(arg, int));
	else if (form == 'u')
		ct += ft_putnbr2((unsigned int)va_arg(arg, unsigned int));
	else if (form == 'x')
		ct += ft_base((unsigned)va_arg(arg, unsigned int), "0123456789abcdef");
	else if (form == 'X')
		ct += ft_base((unsigned)va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (form == 'p')
		ct += ft_printaddress(va_arg(arg, void *));
	else if (form == '%')
		ct += ft_printpct();
	else
		ct += ft_printchar(form);
	return (ct);
}

int	check3(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(arg, str);
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && check3(str[i + 1]) == 1)
		{
			print_len += ft_form(arg, str[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (print_len);
}
