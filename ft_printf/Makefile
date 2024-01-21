NAME=libftprintf.a

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

SRC = ./ft_printf.c \
		./ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(COMPILE) $< -o $@

$(NAME): $(OBJ)
	@$(ARCHIVE) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@echo "Removed Printf objects!"

fclean: clean
	@$(RM) $(NAME)
	@echo Removed $(NAME)!

re: fclean all

.PHONY: all clean fclean re