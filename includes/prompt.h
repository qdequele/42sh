/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 16:57:08 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H
# include <libft.h>
# include <termcap.h>

# define UP ((buf[0] == 27 && buf[1] == 91 && buf[2] == 65))
# define SHIFT_UP ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 65))
# define SHIFT_MAJ_UP ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59 && buf[4] == 49 && buf[5] == 48 && buf[7] == 65))

# define DOWN ((buf[0] == 27 && buf[1] == 91 && buf[2] == 66))
# define SHIFT_DOWN ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 66))
# define SHIFT_MAJ_DOWN ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59 && buf[4] == 49 && buf[5] == 48 && buf[7] == 66))

# define RIGHT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 67))
# define SHIFT_RIGHT ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 67))
# define FN_RIGHT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 70))

# define LEFT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 68))
# define SHIFT_LEFT ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 68))
# define FN_LEFT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 72))

# define BACK_SPACE ((buf[0] == 127 && buf[1] == 0 && buf[2] == 0))
# define DELETE ((buf[0] == 27 && buf[1] == 91 && buf[2] == 51) && buf[3] == 126)
# define ENTER ((buf[0] == 10 && buf[1] == 0 && buf[2] == 0))
# define TAB ((buf[0] == 9 && buf[1] == 0 && buf[2] == 0))

# define HOME ((buf[0] == 27 && buf[1] == 91 && buf[2] == 72))
# define END ((buf[0] == 27 && buf[1] == 91 && buf[2] == 70))
# define IGNORE_1 ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49))
# define QUIT_NORMALE ((buf[0] == 4 && buf[1] == 0 && buf[2] == 0))
# define QUIT_COPY ((buf[0] == 4 && buf[1] == 0 && buf[2] == 0))


# define ALT_C (buf[0] == -61 && buf[1] == -89 && buf[2] == 0)
# define ALT_V (buf[0] == -30 && buf[1] == -120 && buf[2] == -102)
# define ALT_X (buf[0] == -30 && buf[1] == -119 && buf[2] == -120 && buf[3] == 0)
# define ALT_B (buf[0] == -30 && buf[1] == -120 && buf[2] == -85 && buf[3] == 0)

# define SEEK_HISTORY ((buf[0] == 33 && buf[1] == 0 && buf[2] == 0))

/*
** CLSTR- Clear the screen
** MESTR - Turn off all attributes
** MRSTR - Turn on reverse video mode
** TESTR - Strings to end programs using cup
**
** Cursor show
** VESTR - Make cursor appear normal
** VISTR - Make cursor invisible
** USSTR - Begin underline mode
** UESTR - Remove underline mode
**
** Line Edition
** ICSTR - Insert one char
** IMSTR - Insert mode
** EISTR - Exit insert mode
** DCSTR - Delete caractere
** DMSTR - Enter in delete mode
** EDSTR - Exit delete mode
**
** Move
** LESTR - Move to left horizontal
** RISTR - Move to right horizontal
** UPSTR - Move to up vertical
** DOSTR - Move to up vertical
** HOSTR - Move to home
** CRSTR - Move to the begining of the string
** CMSTR - Move to row #1 columns #2
** SCSTR - Save current position of the cursor
** RCSTR - Recover the last save position cursor
*/

# define CLSTR (tgetstr("cl", NULL))
# define USSTR (tgetstr("us", NULL))
# define MRSTR (tgetstr("mr", NULL))
# define TESTR (tgetstr("te", NULL))
# define MESTR (tgetstr("me", NULL))
# define VESTR (tgetstr("ve", NULL))
# define VISTR (tgetstr("vi", NULL))
# define UESTR (tgetstr("ue", NULL))

# define ICSTR (tgetstr("ic", NULL))
# define IMSTR (tgetstr("im", NULL))
# define EISTR (tgetstr("ei", NULL))
# define DCSTR (tgetstr("dc", NULL))
# define DMSTR (tgetstr("dm", NULL))
# define EDSTR (tgetstr("ed", NULL))

# define LESTR (tgetstr("LE", NULL))
# define RISTR (tgetstr("RI", NULL))
# define UPSTR (tgetstr("up", NULL))
# define DOSTR (tgetstr("do", NULL))
# define HOSTR (tgetstr("ho", NULL))
# define CRSTR (tgetstr("cr", NULL))
# define CMSTR (tgetstr("cm", NULL))
# define SCSTR (tgetstr("sc", NULL))
# define RCSTR (tgetstr("rc", NULL))

typedef enum	e_status
{
	TRYING,
	READING,
	FOUND,
	EXIT
}				t_status;

typedef struct	s_prompt
{
	t_list		*line;
	int			i_position;
	int			p_length;
	int			i_copy;
	char		*str_cpy;
	int			copy_mode;
	int			cut_len;
	char		quote_type;
	int			quote_number;
}				t_prompt;

/*
** Prompt.c
*/
void		get_cmd_list(t_list **possibilities, char *last_word);
void		get_builtins_list(t_list **possibilities, char *last_word);
void		get_files_list(t_list **possibilities, char *last_word);
char		*prompt_create_line(void);
/*
** Prompt_actions_autocomplete.c
*/
t_status	action_autocomplete(char *buf);
/*
** Prompt_actions_char.c
*/
t_status	action_insert_char(char *buf);
t_status	action_delete_char(char *buf);
t_status	action_delete_next_char(char *buf);
/*
** Prompt_actions_cmd.c
*/
t_status	action_exec_cmd(char *buf);
t_status	action_ignore_input(char *buf);
t_status	action_insert_char(char *buf);
/*
** Prompt_actions_history.c
*/
t_status	action_history_up(char *buf);
t_status	action_history_down(char *buf);
char		*action_seek_to_history(char *buf);
/*
** Prompt_actions_move.c
*/
t_status	action_move_up(char *buf);
t_status	action_move_down(char *buf);
t_status	action_move_left(char *buf);
t_status	action_move_right(char *buf);
/*
** Prompt_actions_move_word.c
*/
t_status	action_move_next_word(char *buf);
t_status	action_move_last_word(char *buf);
/*
** Prompt_actions_move_ext.c
*/
t_status	action_move_start(char *buf);
t_status	action_move_end(char *buf);
t_status	action_move_max_top(char *buf);
t_status	action_move_max_bottom(char *buf);
/*
** Prompt_find.c
*/
t_status	prompt_find_function(char *buf);
/*
** Prompt_action_list.c
*/
void		*get_actions_normal(void);
void		*get_actions_copy(void);
void		*get_actions_autocomplete(void);
void		*get_actions_history(void);
/*
** Prompt_actions_copy.c
*/
t_status	action_copy_quit(char *buf);
t_status	main_action_copy(char *buf);
t_status	action_copy(char *buf);
/*
** Prompt_actions_paste.c
*/
t_status	action_paste(char *buf);
t_status	action_copy(char *buf);
/*
** Prompt_actions_cut.c
*/
t_status	action_cut(char *buf);
/*
** Prompt_actions_free_copy.c
*/
t_status	action_free(char *buf);
/*
** Prompt_init.c
*/
t_prompt	*init_prompt(void);
char		*get_current_folder(void);
int			get_current_folder_length(void);
/*
** utils
*/
void		clean_prompt(void);
void		string_to_list(char *str);
char		*list_to_string(void);
void		free_char(void *content, size_t size);
void		print_eol(void);
void		inser_char(char c);
void		erase_one_char(void);
void 		erase_x_chars(int x);
/*
** utils_move
*/
void		utils_move_up(void);
void		utils_move_down(void);
void		utils_move_left(void);
void		utils_move_right(void);
/*
** utils_move_ext
*/
void		utils_move_start(void);
void		utils_move_end(void);
void		utils_move_max_top(void);
void		utils_move_max_bottom(void);
/*
** prompt_check_quote.c
*/
<<<<<<< HEAD
int			check_quote();
=======
int 		check_quote();
>>>>>>> f249f06e515103cfac96d2697c761830bd83b499
void		print_error(char flag);
void		display_quote_error(char c);
char		*remove_quote (char type, char *str);
int			quote_close(char *str, char c);
/*
** utils/line_cut.c
*/
char		*before_last_word(char *str, int c);
char		*get_last_word(char *str, int c);
/*
** utils/lst_sort.c
*/
int			sort_by_lexycography(t_list *node);
void 		clean_last_x_char(int i);

#endif
