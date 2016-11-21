# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 14:30:45 by qdequele          #+#    #+#              #
#    Updated: 2016/11/06 20:23:04 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the libft
NAME				=	libft.a

#Define FT_ARR
_FT_ARR_SRC			=	ft_count_column_array.c ft_count_raw_array.c\
						ft_free_array.c ft_join_array.c ft_print_array.c\
						ft_array_to_string.c

FT_ARR_SRC			=	$(addprefix ft_array/,$(_FT_ARR_SRC))

#Define FT_IS
_FT_IS_SRC			=	ft_isprint.c ft_isalnum.c ft_isascii.c ft_isalpha.c \
						ft_isdigit.c ft_isnegative.c ft_isupper.c ft_islower.c\
						ft_isspace.c ft_is_in.c

FT_IS_SRC			=	$(addprefix ft_is/,$(_FT_IS_SRC))

#Define FT_LST
_FT_LST_SRC			=	ft_lstnew.c ft_lstdelone.c ft_lstcount.c ft_lstdel.c\
						ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstaddend.c\
						ft_lstsort.c ft_lstreverse.c ft_lstcpy.c ft_lstadd_at.c\
						ft_lstdel_at.c	ft_lstshow_x.c ft_lstget_at.c \
						ft_lstseek.c ft_lstreduce.c ft_lstremdup.c

FT_LST_SRC			=	$(addprefix ft_lst/,$(_FT_LST_SRC))

#Define FT_MATRIX
_FT_MATRIX_SRC		= ft_matrix_create.c

FT_MATRIX_SRC		=	$(addprefix ft_matrix/,$(_FT_MATRIX_SRC))

#Define FT_MEM
_FT_MEM_SRC			=	ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
						ft_memchr.c ft_memcmp.c ft_memdel.c ft_memalloc.c

FT_MEM_SRC			=	$(addprefix ft_mem/,$(_FT_MEM_SRC))

#Define FT_MEM
_FT_PARSER_SRC		=	ft_parser_option.c ft_parser_option_err.c

FT_PARSER_SRC		=	$(addprefix ft_parser/,$(_FT_PARSER_SRC))

#Define FT_PRINT
_FT_PRINT_SRC		=	ft_putendl.c ft_putchar.c ft_putstr.c ft_putnbr.c\
						ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
						ft_putnbr_fd.c ft_puttab.c ft_print_n_time.c\
						ft_printf.c ft_printf_flags.c ft_console.c\
						ft_console_flags.c

FT_PRINT_SRC		=	$(addprefix ft_print/,$(_FT_PRINT_SRC))

#Define FT_STR
_FT_STR_SRC			=	ft_striter.c ft_striteri.c ft_strdel.c ft_strclr.c\
						ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c\
						ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
						ft_strnew.c ft_strcat.c ft_strncat.c ft_strlcat.c \
						ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcmp.c\
						ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strstr.c\
						ft_strlen.c ft_strrev.c ft_strnstr.c ft_strfjoin.c\
						ft_strcut.c ft_str_to_tab.c ft_freejoin.c\
						ft_skip_char.c

FT_STR_SRC			=	$(addprefix ft_str/,$(_FT_STR_SRC))

#Define FT_UTILS
_FT_UTILS_SRC		=	ft_atoi.c ft_itoa.c ft_bzero.c ft_toupper.c ft_tolower.c\
						ft_nbrlen.c ft_nbrlen_base.c ft_wordlen.c ft_wordcount.c\
						ft_itoa_base.c ft_get_next_line.c ft_colors.c \
						ft_console.c ft_match.c ft_nmatch.c

FT_UTILS_SRC		=	$(addprefix ft_utils/,$(_FT_UTILS_SRC))


#Define Global LIBFT files
SRC					=	$(FT_ARR_SRC) $(FT_IS_SRC) $(FT_LST_SRC) $(FT_MEM_SRC)\
						$(FT_PRINT_SRC) $(FT_STR_SRC) $(FT_UTILS_SRC) $(FT_MATRIX_SRC)\
						$(FT_PARSER_SRC)
INCLUDES			=	./includes/
OBJ					=	$(SRC:.c=.o)
CFLAGS				=	-Wall -Wextra -Werror -g -ggdb

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(NAME) " - compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@rm -rf $(OBJ)
	@echo $(NAME) " - Clean all .o files"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo $(NAME) " - Clean .a"

re: fclean all
