/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergejleskin <sergejleskin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:38:31 by sergejleski       #+#    #+#             */
/*   Updated: 2022/02/09 20:39:29 by sergejleski      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((n--) > 0)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		if (!*ss1)
			return (0);
		ss1++;
		ss2++;
	}
	return (0);
}
