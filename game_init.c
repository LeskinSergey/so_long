/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:40:03 by sbombadi          #+#    #+#             */
/*   Updated: 2022/02/12 02:53:03 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_game *g)
{
	g->moves++;
	printf("%d\nwin\n", g->moves);
	mlx_clear_window(g->mlx, g->window);
	exit (0);
}

static void	put_image(t_game *g)
{
	int	x;

	x = 40;
	g->img->player = mlx_xpm_file_to_image(g->mlx, "pic/player.xpm", &x, &x);
	g->img->item = mlx_xpm_file_to_image(g->mlx, "pic/bomb.xpm", &x, &x);
	g->img->door = mlx_xpm_file_to_image(g->mlx, "pic/door.xpm", &x, &x);
	g->img->wall = mlx_xpm_file_to_image(g->mlx, "pic/wall.xpm", &x, &x);
	g->img->back = mlx_xpm_file_to_image(g->mlx, "pic/background.xpm", &x, &x);
}

static void	draw_images_1(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->window,
			g->img->wall, x * 40, y * 40);
	if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->window,
			g->img->back, x * 40, y * 40);
	if (g->map[y][x] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->window,
			g->img->player, x * 40, y * 40);
		g->pos_x = x;
		g->pos_y = y;
	}
	if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->window,
			g->img->item, x * 40, y * 40);
	if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->window,
			g->img->door, x * 40, y * 40);
}

void	draw_images(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->s_y)
	{
		x = 0;
		while (x < g->s_x)
		{
			draw_images_1(g, x, y);
			x++;
		}
		y++;
	}
}

void	so_long(t_game *g)
{
	g->mlx = mlx_init();
	g->img = malloc(sizeof(t_i));
	ft_memset(g->img, 0, sizeof(t_i));
	g->window = mlx_new_window(g->mlx, g->s_x * 40, g->s_y * 40, "game");
	put_image(g);
	draw_images(g);
	mlx_hook(g->window, 02, 0, key_event, g);
	mlx_hook(g->window, 17, 0, free_all, g);
	mlx_loop_hook(g->mlx, rewrite_map, g);
	mlx_loop(g->mlx);
}
