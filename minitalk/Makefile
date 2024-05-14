NAME = minitalk
NAME_BONUS = minitalk_bonus
NAME_SERVER = server
NAME_CLIENT = client

CC = cc
HEADER = ./libft
CFLAGS = -Wextra -Werror -Wall -g -I$(HEADER)
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

LIBFT_DIR = ./libft

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC_CLIENT =	./src/client.c 

SRC_SERVER =	./src/server.c 

SRC_CLIENT_BONUS = ./src_bonus/client_bonus.c

SRC_SERVER_BONUS = ./src_bonus/server_bonus.c


all: $(NAME)

$(NAME): $(SRC_SERVER) $(SRC_CLIENT)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I. -I$(HEADER) $(SRC_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)
	$(CC) $(CFLAGS) -I. -I$(HEADER) $(SRC_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)
	@echo "$(YELLOW)	MINITALK COMPILED! 📲✅$(RESET)"
	@echo "$(YELLOW)	Run ./client or ./server$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRC_SERVER_BONUS) $(SRC_CLIENT_BONUS)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I. -I$(HEADER) $(SRC_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)
	$(CC) $(CFLAGS) -I. -I$(HEADER) $(SRC_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)
	@echo "$(YELLOW)	MINITALK BONUS COMPILED! 📲✅$(RESET)"
	@echo "$(YELLOW)	Run ./client or ./server$(RESET)"

RM = rm -f

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(RED)	MINITALK DESTROYED 📵 $(RESET)"

re: fclean all

.PHONY: all clean fclean re
.SILENT: