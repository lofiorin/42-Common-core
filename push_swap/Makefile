NAME = push_swap

BONUS = checker

LIBFT = libft/libft.a

# ---Sources---

SRC = main.c \
	utils.c \
	init.c \
	minisort.c \
	push.c \
	rotate.c \
	sort_init.c \
	sort.c \
	swap.c \
	utils2.c

SRC_BONUS = checker_bonus.c \
	utils.c \
	init.c \
	minisort.c \
	push.c \
	rotate.c \
	sort_init.c \
	sort.c \
	swap.c \
	utils2.c

OBJ = $(SRC:.c=.o)

# ----Rules----

CFLAGS = -Wall -Wextra -Werror -g
COMPILE = cc $(CFLAGS)
RM = rm -rf

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	echo "PUSH SWAP IS COMPILED"

bonus: $(BONUS)

$(BONUS): $(SRC) $(SRC_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o $(BONUS)
	echo "PUSH SWAP BONUS IS COMPILED"

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C libft clean

fclean: clean
	$(MAKE) -C libft fclean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@echo "[$(NAME)]:\tPROGRAM DELETED"

re: fclean all

%.o: %.C
	@$(COMPILE) -c $< -o $@

# ---Valgrind---

ARG = "1 3 2 0"
VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all --quiet --track-origins=yes --tool=memcheck --keep-debuginfo=yes

valgrind : all
	@$(VALGRIND) ./$(NAME) $(ARG)

valgrindre: re valgrind

# ----Other----
.PHONY: all clean fclean re valgrind bonus

.SILENT: