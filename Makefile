# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 14:57:05 by qdequele          #+#    #+#              #
#    Updated: 2016/10/14 19:46:17 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		=	42sh
LIB			=	./libft/libft.a
_SRC		=	builtins/builtins_cd.c\
				builtins/builtins_echo.c\
				builtins/builtins_env.c\
				builtins/builtins_exit.c\
				builtins/builtins_history.c\
				builtins/builtins_init.c\
				builtins/builtins_setenv.c\
				builtins/builtins_unsetenv.c\
				cmd/cmd.c\
				env/env_parser.c\
				env/env_utils.c\
				prompt/actions/prompt_actions_char.c\
				prompt/actions/prompt_actions_cmd.c\
				prompt/actions/prompt_actions_history.c\
				prompt/actions/prompt_actions_move.c\
				prompt/actions/prompt_actions_move-word.c\
				prompt/actions/prompt_actions_move-ext.c\
				prompt/actions/prompt_actions_copy.c\
				prompt/actions/prompt_actions_paste.c\
				prompt/utils/prompt_utils_clear.c\
				prompt/utils/prompt_utils_move.c\
				prompt/utils/prompt_utils_move-ext.c\
				prompt/utils/prompt_utils_free-char.c\
				prompt/utils/prompt_utils_show-end-of-line.c\
				prompt/utils/prompt_utils_string-to-list.c\
				prompt/prompt.c\
				prompt/prompt_find.c\
				prompt/prompt_init.c\
				shell/shell.c\
				shell/shell_init.c\
				shell/shell_print.c\
				signals/signal.c\
				signals/signal_handlers.c\
				term/term.c\
				term/term_utils.c\
				main.c

SRC			=	$(addprefix srcs/,$(_SRC))
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -g -ggdb
INCLUDES	=	-I./libft/ -I./includes/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@gcc $(CFLAGS) -L /usr/lib -ltermcap $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@echo $(NAME) " - compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@make clean -C libft
	@/bin/rm -rf $(OBJ)
	@echo $(NAME) " - Clean all .o files"

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo $(NAME) " - Clean executable"

re: fclean all

.PHONY: all, clean, fclean, re
