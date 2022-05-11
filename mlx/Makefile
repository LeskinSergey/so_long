#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
CC = gcc

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

NB = $(words $(SRC))
INDEX = 0

all: $(NOM)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval PERCENT=$(shell expr $(INDEX) '*' 100 / $(NB)))
	@$(eval PROGRESS=$(shell expr $(INDEX) '*' 30 / $(NB)))
	@printf "\r\033[38;5;74mMAKE MLX %2d%%\033[0m \033[48;5;75m%*s\033[0m %s\033[K" $(PERCENT) $(PROGRESS) #"" $(notdir $@)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

%.o : %.m
	@$(CC) $(CFLAGS) -c $< -o $@

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@printf "\r\033[38;5;83mMLX DONE\033[0m\033[K\n"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
