# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 14:57:05 by qdequele          #+#    #+#              #
#    Updated: 2016/10/31 13:31:31 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		=	42sh
LIB			=	./libft/libft.a
_SRC		=	builtins/cd.c\
				builtins/echo.c\
				builtins/env.c\
				builtins/exit.c\
				builtins/history.c\
				builtins/init.c\
				builtins/read.c\
				builtins/setenv.c\
				builtins/unsetenv.c\
				builtins/export.c\
				builtins/set.c\
				builtins/unset.c\
				builtins/utils/parser.c\
				builtins/utils/env.c\
				builtins/utils/remove_key.c\
				builtins/utils/vars.c\
				cmd/cmd.c\
				lexer/utils/body.c\
				lexer/utils/fork_close.c\
				lexer/exec.c\
				lexer/heredoc.c\
				lexer/lexer.c\
				lexer/parse_redirection.c\
				lexer/pipe.c\
				lexer/redirect_entry.c\
				lexer/redirection.c\
				prompt/actions/autocomplete.c\
				prompt/actions/char.c\
				prompt/actions/cmd.c\
				prompt/actions/history.c\
				prompt/actions/move.c\
				prompt/actions/move_word.c\
				prompt/actions/move_ext.c\
				prompt/actions/copy.c\
				prompt/actions/paste.c\
				prompt/actions/free_copy.c\
				prompt/actions/seek_to_history.c\
				prompt/actions/cut.c\
				prompt/utils/clear.c\
				prompt/utils/conversion.c\
				prompt/utils/move.c\
				prompt/utils/move_ext.c\
				prompt/utils/free_char.c\
				prompt/utils/line_cut.c\
				prompt/utils/lst_sort.c\
				prompt/utils/erase.c\
				prompt/utils/show_end_of_line.c\
				prompt/prompt.c\
				prompt/actions_list.c\
				prompt/find.c\
				prompt/init.c\
				prompt/check_quote.c\
				shell/shell.c\
				shell/init.c\
				shell/print.c\
				shell/utils.c\
				signals/signal.c\
				signals/handlers.c\
				term/term.c\
				term/utils.c\
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
