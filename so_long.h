/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:39:13 by sergejleski       #+#    #+#             */
/*   Updated: 2022/02/12 01:19:52 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"

typedef struct s_i
{
	void	*wall;
	void	*back;
	void	*item;
	void	*player;
	void	*door;
}	t_i;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		moves;
	int		cnt_p;
	int		coins;
	int		exit;
	int		s_x;
	int		s_y;
	int		pos_x;
	int		pos_y;
	t_i		*img;
	char	**map;
}	t_game;

# define BUFFER_SIZE 21

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_line_res(char *line);
char	*ft_get_remainder(char *remainder);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
void	check_map(t_game *g, char *argv);
void	check_map_1(t_game *g);
void	check_map_2(t_game *g);
void	check_map_3(t_game *g);
void	check_map_4(t_game *g);
int		find_s_y(char *a);
void	so_long(t_game *g);
void	draw_images(t_game *g);
int		rewrite_map(t_game *g);
int		key_event(int code, t_game *g);
void	win(t_game *g);
int		free_all(t_game *g);
#endif
