NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
RM = rm -rf
LINKS_LINUX = -lX11 -lm -lXext

MINILIBX = mlx/libmlx.a
LIBFT = libft/libft.a
INCLUDES = -Imlx -Ilibft
LIBS = -Lmlx -lmlx -Llibft -lft

SRC = src/ft_render.c \
	src/ft_movement.c \
	src/ft_map_gen.c \
	src/ft_exit.c \
	src/ft_parsing.c \
	src/ft_control.c \
	src/main.c


BONUS = src_bonus/ft_render_bonus.c \
	src_bonus/ft_movement_bonus.c \
	src_bonus/ft_map_gen_bonus.c \
	src_bonus/ft_enemy_movement_bonus.c \
	src_bonus/ft_exit_bonus.c \
	src_bonus/ft_parsing_bonus.c \
	src_bonus/ft_control_bonus.c \
	src_bonus/main_bonus.c


OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C mlx/
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) $(LINKS_LINUX) -o $(NAME)
	echo "SO_LONG IS COMPILED"

bonus: $(BONUS_OBJ)
	make -C libft/
	make -C mlx/
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJ) $(LIBS) $(LINKS_LINUX) -o $(NAME)
	echo "SO_LONG BONUS IS COMPILED"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

download:
	@wget https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz
	@tar -xf minilibx-linux.tgz
	@mv minilibx-linux mlx
	@$(RM) minilibx-linux.tgz

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	@$(MAKE) -iC mlx clean || echo -n ""
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) mlx && echo "[MLX]:\t\tDELETED MINILIBX FOLDER!"
	make clean -C libft/
	$(RM) $(NAME)

re: fclean download all

.SILENT:
