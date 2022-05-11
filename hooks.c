/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:41:33 by sbombadi          #+#    #+#             */
/*   Updated: 2022/02/12 02:43:34 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	go_up(t_game *g)
{
	if (g->map[g->pos_y - 1][g->pos_x] != '1')
	{
		if (g->map[g->pos_y - 1][g->pos_x] == '0')
		{
			g->map[g->pos_y - 1][g->pos_x] = 'P';
			g->map[g->pos_y][g->pos_x] = '0';
		}
		if (g->map[g->pos_y - 1][g->pos_x] == 'C')
		{
			g->map[g->pos_y - 1][g->pos_x] = 'P';
			g->map[g->pos_y][g->pos_x] = '0';
			g->coins--;
		}
		if (g->map[g->pos_y - 1][g->pos_x] == 'E' && g->coins == 0)
			win(g);
		if (g->map[g->pos_y - 1][g->pos_x] != 'E')
			g->moves++;
		g->pos_y--;
		printf("%d\n", g->moves);
	}
}

static void	go_down(t_game *g)
{
	if (g->map[g->pos_y + 1][g->pos_x] != '1')
	{
		if (g->map[g->pos_y + 1][g->pos_x] == '0')
		{
			g->map[g->pos_y + 1][g->pos_x] = 'P';
			g->map[g->pos_y][g->pos_x] = '0';
		}
		if (g->map[g->pos_y + 1][g->pos_x] == 'C')
		{
			g->map[g->pos_y + 1][g->pos_x] = 'P';
			g->map[g->pos_y][g->pos_x] = '0';
			g->coins--;
		}
		if (g->map[g->pos_y + 1][g->pos_x] == 'E' && g->coins == 0)
			win(g);
		if (g->map[g->pos_y + 1][g->pos_x] != 'E')
			g->moves++;
		g->pos_y++;
		printf("%d\n", g->moves);
	}
}

static void	go_left(t_game *g)
{
	if (g->map[g->pos_y][g->pos_x - 1] != '1')
	{
		if (g->map[g->pos_y][g->pos_x - 1] == '0')
		{
			g->map[g->pos_y][g->pos_x - 1] = 'P';
			g->map[g->pos_y][g->pos_x] = '0';
		}
		if (g->map[g->pos_y][g->pos_x - 1] == 'C')
		{
			g->map[g->pos_y][g->pos_x - 1] = 'P';
			g->map[g->pos_y][g->pos_x] = '0';
			g->coins--;
		}
		if (g->map[g->pos_y][g->pos_x - 1] == 'E' && g->coins == 0)
			win(g);
		if (g->map[g->pos_y][g->pos_x - 1] != 'E')
			g->moves++;
		g->pos_x--;
		printf("%d\n", g->moves);
	}
}

static void	go_right(t_game *g)
{
	if (g->map[g->pos_y][g->pos_x + 1] != '1')
	{
		if (g->map[g->pos_y][g->pos_x + 1] == '0')
		{
			g->map[g->pos_y][g->pos_x + 1] = 'P';
			g->map[g->pos_y][g->pos_x] = '0';
		}
		if (g->map[g->pos_y][g->pos_x + 1] == 'C')
		{
			g->map[g->pos_y][g->pos_x + 1] = 'P';
			g->map[g->pos_y][g->pos_x] = '0';
			g->coins--;
		}
		if (g->map[g->pos_y][g->pos_x + 1] == 'E' && g->coins == 0)
			win(g);
		if (g->map[g->pos_y][g->pos_x + 1] != 'E')
			g->moves++;
		g->pos_x++;
		printf("%d\n", g->moves);
	}
}

int	key_event(int code, t_game *g)
{
	if (code == 13)
		go_up(g);
	if (code == 1)
		go_down(g);
	if (code == 0)
		go_left(g);
	if (code == 2)
		go_right(g);
	if (code == 53)
		free_all(g);
	return (0);
}
