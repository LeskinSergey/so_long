/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:38:22 by sergejleski       #+#    #+#             */
/*   Updated: 2022/02/12 02:41:25 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	check_map_4(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < g->s_y)
	{
		i = 0;
		while (i < g->s_x)
		{
			if (g->map[j][i] == 'P')
				g->cnt_p++;
			if (g->map[j][i] == 'C')
				g->coins++;
			if (g->map[j][i] == 'E')
				g->exit++;
			i++;
		}
		j++;
	}
	if (g->cnt_p != 1 || g->coins < 1 || g->exit < 1)
	{
		write(1, "error\n", 6);
		exit (1);
	}
}

void	check_map_3(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < g->s_y)
	{
		i = 0;
		while (i < g->s_x)
		{
			if (g->map[j][i] != '1' && g->map[j][i] != '0'
				&& g->map[j][i] != 'P' && g->map[j][i] != 'C'
				&& g->map[j][i] != 'E')
			{
				write(1, "error\n", 6);
				exit (1);
			}
			i++;
		}
		j++;
	}
	check_map_4(g);
}

void	check_map_2(t_game *g)
{
	int	l;

	l = -1;
	while (l++ < g->s_y - 1)
	{
		if (g->map[l][0] != '1' || g->map[l][g->s_x - 1] != '1')
		{
			write(1, "error\n", 6);
			exit (1);
		}
	}
	l = -1;
	while (l++ < g->s_x - 1)
	{
		if (g->map[0][l] != '1' || g->map[g->s_y - 1][l] != '1')
		{
			write(1, "error\n", 6);
			exit (1);
		}
	}
	check_map_3(g);
}

void	check_map_1(t_game *g)
{
	int	l;

	l = 0;
	g->s_x = map_len(g->map[l]);
	while (l++ < g->s_y - 1)
	{
		if (g->s_x != map_len(g->map[l]))
		{
			write(1, "error\n", 6);
			exit (1);
		}
	}
	check_map_2(g);
}
