NAME = minishell
HEAD = srcs/includes/minishell.h
PRINTF_DIR = srcs/ft_printf/
LIBFT_DIR = srcs/libft/
PRINTF_LIB = libftprintf.a
LIBFT_LIB = libft.a
MKFILE = Makefile
SRC = srcs/*.c
FLAG = -O2
#FLAG += -g
#FLAG += -lncurses
#FLAG += -fsanitize=address
#FLAG += -fsanitize=undefined
#FLAG += -fno-omit-frame-pointer
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(HEAD) $(MKFILE)
	@make -C $(LIBFT_DIR)/
	@make -C $(PRINTF_DIR)/
	@gcc $(SRC) $(FLAG) $(PRINTF_DIR)/$(PRINTF_LIB)\
		$(LIBFT_DIR)/$(LIBFT_LIB) -o $(NAME)

clean:
	@echo "[shell] Deleting:\033[33m *.o\033[0m"
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR)/ clean
	@make -C $(PRINTF_DIR)/ clean

fclean: clean
	@echo "[shell] Deleting:\033[33m $(NAME)\033[0m"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR)/ fclean
	@make -C $(PRINTF_DIR)/ fclean

re: fclean all

git :
	@git add .
	@git commit -m "${MSG}"

gitp : fclean git
	git push

.PHONY: clean fclean re git gitp
