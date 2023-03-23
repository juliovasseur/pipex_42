/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:58:29 by jvasseur          #+#    #+#             */
/*   Updated: 2022/12/12 16:42:32 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(long long nb);
int	ft_putnbr2(unsigned int nb);
int	ft_base(unsigned int nbr, char *base);
int	ft_printpct(void);
int	ft_printaddress(void *nb);

#endif
