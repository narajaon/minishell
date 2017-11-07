NAME = minishell
HEAD = includes/minishell.h
PRINTF_DIR = ft_printf/
LIBFT_DIR = libft/
PRINTF_LIB = libftprintf.a
LIBFT_LIB = libft.a
MKFILE = Makefile
SRC = \
	add_cmd_to_history.c \
	cd_cmd.c \
	cmd_funs.c \
	env_setenv_funs.c \
	exec_cmd.c \
	export_funs.c \
	ft_arg_split.c \
	ft_tab_to_list.c \
	get_str_in_quotes.c \
	global_strucs.c \
	hash_funct.c \
	init_local_var.c \
	main.c \
	parse_check_bin.c \
	path_manip.c \
	signal_handler.c \
	utils.c
FLAG = -O2
#FLAG += -fsanitize=address
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
