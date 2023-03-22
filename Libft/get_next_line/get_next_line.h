/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:35:47 by marvin            #+#    #+#             */
/*   Updated: 2022/11/09 02:35:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

char	*get_next_line(int fd);
char	*ft_strchr1(const char *s, int c);
void	*ft_callocgnl(size_t c, size_t size);
char	*ft_strjoingnl(char const *s1, char const *s2);
size_t	ft_strlen1(const char *c);
size_t	ft_strlen2(char *str);

#endif
