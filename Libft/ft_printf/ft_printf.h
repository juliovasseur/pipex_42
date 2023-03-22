#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <string.h>
# include<stdlib.h>
# include<unistd.h>
# include<stddef.h>
# include<limits.h>

int ft_printf(const char *str, ...);
int	ft_putstr(char *s);
int ft_putchar(char c);
int ft_putnbr(long long nb);
int ft_putnbr2(unsigned nb);
int	ft_putnbr_base(unsigned nbr, char *base);
int ft_printpct(void);
int	ft_printaddress(void *nb);

#endif
