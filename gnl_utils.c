/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergejleskin <sergejleskin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:38:43 by sergejleski       #+#    #+#             */
/*   Updated: 2022/02/09 20:39:25 by sergejleski      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	t;
	size_t	i;
	char	*newstr;

	t = 0;
	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	newstr = malloc(sizeof(*s1) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
		newstr[t++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[t++] = s2[i++];
	newstr[t] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_line_res(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(remainder) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (remainder[i])
		str[j++] = remainder[i++];
	str[j] = '\0';
	free(remainder);
	return (str);
}
