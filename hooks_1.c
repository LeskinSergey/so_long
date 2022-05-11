/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:41:36 by sbombadi          #+#    #+#             */
/*   Updated: 2022/02/12 02:42:09 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(t_game *g)
{
	free(g);
	exit (1);
}

int	rewrite_map(t_game *g)
{
	mlx_clear_window(g->mlx, g->window);
	draw_images(g);
	return (0);
}
