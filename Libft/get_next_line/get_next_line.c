/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:09:36 by marvin            #+#    #+#             */
/*   Updated: 2022/11/08 22:09:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ftgetnextline(char *buf)
{
	int		i;
	char	*stash;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	stash = ft_callocgnl((i + 1), 1);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		stash[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		stash[i] = buf[i];
		i++;
	}
	return (stash);
}

char	*ft_takeline(char *buf)
{
	int		i;
	int		k;
	char	*takeline;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	takeline = (char *)malloc(sizeof(char) * (ft_strlen1(buf) - i + 1));
	if (!takeline)
		return (NULL);
	i++;
	k = 0;
	while (buf[i])
		takeline[k++] = buf[i++];
	takeline[k] = '\0';
	free(buf);
	return (takeline);
}

char	*ft_clearline(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoingnl(stash, buffer);
	free(stash);
	return (tmp);
}

char	*read_and_stash_line(int fd, char *buf)
{
	char	*buffer;
	int		reads;

	if (!buf)
		buf = ft_callocgnl(1, 1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reads = 1;
	while (!ft_strchr1(buf, '\n') && reads > 0)
	{
		reads = read(fd, buffer, BUFFER_SIZE);
		if (reads == -1)
		{
			free(buf);
			free(buffer);
			return (NULL);
		}
		buffer[reads] = '\0';
		buf = ft_clearline(buf, buffer);
	}
	free(buffer);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_and_stash_line(fd, buf);
	if (!buf)
		return (NULL);
	stash = ftgetnextline(buf);
	buf = ft_takeline(buf);
	if (buf == NULL)
	{
		free(buf);
		buf = NULL;
	}
	return (stash);
}
