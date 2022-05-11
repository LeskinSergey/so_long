NAME = so_long

FILES =	ft_memset.c \
		ft_strrchr.c \
		gnl.c \
		check_map.c \
		ft_strcmp.c \
		game_init.c \
		gnl_utils.c \
		so_long.c \
		hooks.c \
		hooks_1.c \

HEADER = so_long.h

OBJDIR = objs/
OBJS = $(FILES_O:.c=.o)
FILES_O = $(addprefix objs/, $(notdir $(FILES)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Imlx
MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx
MLX_D = mlx/
MLX = $(MLX_D)libmlx.a

objs/%.o : %.c Makefile $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir objs/


$(NAME) : $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(MLXFLAGS) $(OBJS) -Lmlx -lmlx

$(MLX):
	@$(MAKE) -C $(MLX_D)

clean:
	@$(MAKE) -C $(MLX_D) clean
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re: fclean all
