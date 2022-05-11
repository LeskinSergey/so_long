/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergejleskin <sergejleskin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:38:35 by sergejleski       #+#    #+#             */
/*   Updated: 2022/02/09 20:39:27 by sergejleski      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	char	i;
	char	*str;
	int		j;

	j = 0;
	i = (char)c;
	str = (char *)s;
	while (str[j])
		j++;
	while (j >= 0)
	{
		if (str[j] == i)
			return (&str[j]);
		j--;
	}
	return (NULL);
}
