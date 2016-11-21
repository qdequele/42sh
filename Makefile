# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 14:57:05 by qdequele          #+#    #+#              #
#    Updated: 2016/11/20 19:23:13 by bjamin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		=	42sh
LIB			=	./libft/libft.a
_SRC		=	builtins/utils/parser.c\
				builtins/utils/env.c\
				builtins/utils/option_parser.c\
				builtins/utils/remove_key.c\
				builtins/utils/vars.c\
				builtins/utils/vars_free.c\
				builtins/utils/read_create_var.c\
				builtins/utils/one_history_error.c\
				builtins/cd.c\
				builtins/cd_help.c\
				builtins/echo.c\
				builtins/env.c\
				builtins/exit.c\
				builtins/help.c\
				builtins/history.c\
				builtins/init.c\
				builtins/read.c\
				builtins/setenv.c\
				builtins/unsetenv.c\
				builtins/export.c\
				builtins/set.c\
				builtins/unset.c\
				builtins/readonly.c\
				builtins/unreadonly.c\
				builtins/jobs.c\
				builtins/fg.c\
				builtins/bg.c\
				exec/exec_job.c\
				exec/exec_process.c\
				exec/exec_setup.c\
				exec/job_control.c\
				exec/job_info.c\
				exec/job_notification.c\
				exec/job_utils.c\
				lexer/tokens/is_token_generic.c\
				lexer/tokens/is_token_quotes_parent.c\
				lexer/tokens/is_token_redir.c\
				lexer/tokens/is_token_separator.c\
				lexer/check_lexer.c\
				lexer/lexer_quotes_controller.c\
				lexer/main_lexer.c\
				lexer/token_to_list.c\
				lexer/utils/remove_quote.c\
				parser/get_cmd_env.c\
				parser/main_parser.c\
				parser/parser_argv.c\
				parser/parser_asserts.c\
				parser/parser_cleanup.c\
				parser/parser_io_channel.c\
				parser/parser_io_utils.c\
				parser/parser_io_channel_heredoc.c\
				parser/parser_replace_vars.c\
				prompt/actions/common/char.c\
				prompt/actions/common/move.c\
				prompt/actions/common/move_ext.c\
				prompt/actions/common/cmd.c\
				prompt/actions/copy/copy.c\
				prompt/actions/copy/cut.c\
				prompt/actions/copy/free_copy.c\
				prompt/actions/copy/paste.c\
				prompt/actions/normal/autocomplete.c\
				prompt/actions/normal/history.c\
				prompt/actions/normal/prompt_length.c\
				prompt/actions/normal/read.c\
				prompt/actions/normal/seek_to_history.c\
				prompt/actions/normal/sync_history.c\
				prompt/actions/normal/sync_vars.c\
				prompt/actions/quote/prompt_length.c\
				prompt/actions/quote/read.c\
				prompt/utils/char.c\
				prompt/utils/clean.c\
				prompt/utils/conversion.c\
				prompt/utils/move.c\
				prompt/utils/move_ext.c\
				prompt/utils/print_error_quote.c\
				prompt/utils/line_cut.c\
				prompt/utils/erase.c\
				prompt/utils/get_possibilities.c\
				prompt/utils/show_end_of_line.c\
				prompt/find.c\
				prompt/init.c\
				shell/init.c\
				shell/print.c\
				shell/signal.c\
				shell/term.c\
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

test		:	re
	@rm -r -f test/spec/42sh/subshell
	@rm -r -f test/spec/42sh/quoting/simple-quotes/mixed/escaping
	@rm -r -f test/spec/42sh/quoting/double-quotes/mixed/escaping
	@rm -r -f test/spec/bonuses/tilde-expansion
	@rm -r -f test/spec/42sh/globbing
	@rm -r -f test/spec/42sh/escaping
	@cd test && bash 42ShellTester.sh $$PWD/../$(NAME) --reference "bash"

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

leaks:
	valgrind --leak-check=full --suppressions=./valgrind.supp ./42sh

run:
	./42sh

start: run

.PHONY: all, clean, fclean, re

