# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 14:57:05 by qdequele          #+#    #+#              #
#    Updated: 2016/10/12 16:17:54 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		=	42sh
LIB			=	./libft/libft.a
_SRC		=	builtins/builtins_cd.c\
				builtins/builtins_env.c\
				builtins/builtins_exit.c\
				builtins/builtins_history.c\
				builtins/builtins_init.c\
				builtins/builtins_setenv.c\
				builtins/builtins_unsetenv.c\
				builtins/builtins_echo.c\
				cmd/cmd.c\
				env/env_parser.c\
				env/env_utils.c\
				prompt/actions/prompt_actions_char.c\
				prompt/actions/prompt_actions_cmd.c\
				prompt/actions/prompt_actions_history.c\
				prompt/actions/prompt_actions_move.c\
				prompt/actions/prompt_actions_move_word.c\
				prompt/prompt.c\
				prompt/prompt_find.c\
				prompt/prompt_init.c\
				prompt/utils/clear_prompt.c\
				promptutils/string_to_list.c\
				shell/shell.c\
				shell/shell_init.c\
				shell/shell_print.c\
				signals/signal.c\
				signals/signal_handlers.c\
				term/term.c\
				term/term_utils.c\
				42sh.c

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
