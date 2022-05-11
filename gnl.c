/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergejleskin <sergejleskin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:38:53 by sergejleski       #+#    #+#             */
/*   Updated: 2022/02/10 22:40:39 by sergejleski      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_find_str(int fd, char *line)
{
	char		*buffer;
	int			flag;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	flag = 1;
	while (!find_n(line) && flag)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = ft_find_str(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_line_res(remainder);
	remainder = ft_get_remainder(remainder);
	return (line);
}
