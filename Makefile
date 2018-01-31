NAME:=minishell
CC:=gcc

RM:=/bin/rm -f
MKDIR:=mkdir -p

ifeq ($(DEBUG),yes)
CFLAGS:=-g3 -fsanitize=address
else
CFLAGS:= -O2 -Wall -Wextra -Werror
endif
INC_D:=inc
SCR_D:=src
LIB_D:=lib
OBJ_D:=obj
HEAD =$(INC_D)/minishell.h

INCLUDES = -I inc \
		-I lib/ft_printf/inc \
		-I lib/libft/inc \

LIBRARIES = -L lib/ft_printf -lftprintf \
			-L lib/libft -lft \
			-lcurses

ITEM = \
	main.o \
	add_cmd_to_history.o \
	cd_cmd.o \
	cmd_funs.o \
	env_setenv_funs.o \
	exec_cmd.o \
	export_funs.o \
	ft_arg_split.o \
	ft_tab_to_list.o \
	get_str_in_quotes.o \
	global_strucs.o \
	hash_funct.o \
	init_local_var.o \
	parse_check_bin.o \
	path_manip.o \
	signal_handler.o \
	utils.o



OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

vpath %.c src

vpath %.h inc lib/libft/inc lib/ft_printf/inc

all: $(NAME)

$(NAME): $(OBJ) $(HEAD) Makefile
	@$(MAKE) -C lib/libft
	@$(MAKE) -C lib/ft_printf
	@$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(LIBRARIES) $(OBJ)

./${OBJ_D}/%.o: %.c 
	@$(MKDIR) $(OBJ_D)
	@$(CC) $(CFLAGS) -c -o $@ $<  $(INCLUDES)

clean:
	@$(MAKE) -C lib/ft_printf clean
	@$(MAKE) -C lib/libft clean
	@$(RM) -r $(OBJ_D)

fclean: clean
	@$(MAKE) -C lib/ft_printf fclean
	@$(MAKE) -C lib/libft fclean
	@$(RM) $(NAME)

re: fclean all

git :
	@git add .
	@git commit -m "${MSG}"

gitp : fclean git
	git push

.PHONY: clean fclean re git gitp
