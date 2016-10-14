/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/13 12:56:45 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H
# include <libft.h>
# include <termcap.h>

# define SHIFT_UP ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 65))
# define UP ((buf[0] == 27 && buf[1] == 91 && buf[2] == 65))
# define SHIFT_DOWN ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 66))
# define DOWN ((buf[0] == 27 && buf[1] == 91 && buf[2] == 66))
# define SHIFT_RIGHT ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 67))
# define RIGHT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 67))
# define FN_RIGHT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 70))
# define SHIFT_LEFT ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 68))
# define LEFT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 68))
# define FN_LEFT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 72))
# define BACK_SPACE ((buf[0] == 127 && buf[1] == 0 && buf[2] == 0))
# define DELETE ((buf[0] == 27 && buf[1] == 91 && buf[2] == 51) && buf[3] == 126)
# define ENTER ((buf[0] == 10 && buf[1] == 0 && buf[2] == 0))
# define HOME ((buf[0] == 27 && buf[1] == 91 && buf[2] == 72))
# define END ((buf[0] == 27 && buf[1] == 91 && buf[2] == 70))
# define TAB ((buf[0] == 9 && buf[1] == 0 && buf[2] == 0))
# define IGNORE_1 ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49))
# define QUIT ((buf[0] == 4 && buf[1] == 0 && buf[2] == 0))

/*
** CL_STR- Clear the screen
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

# define LESTR (tgetstr("le", NULL))
# define RISTR (tgetstr("ri", NULL))
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
	FOUND
}				t_status;

typedef struct	s_prompt
{
	t_list		*line;
	int			i_position;
	int			p_length;
	int			l_length;
	int			start_col;
	int			start_line;
	int			end_col;
	int			end_line;
}				t_prompt;

/*
** Prompt.c
*/
char		*prompt_create_line(void);
char		*convert_prompt_to_string(void);
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
t_status	action_shell_quit(char *buf);
t_status	action_insert_char(char *buf);
/*
** Prompt_actions_history.c
*/
t_status	action_history_up(char *buf);
t_status	action_history_down(char *buf);
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
t_status	action_move_start(char *buf);
t_status	action_move_end(char *buf);
/*
** Prompt_find.c
*/
t_status	prompt_find_function(char *buf);
/*
** Prompt_init.c
*/
t_prompt	*init_prompt(void);
char		*get_current_folder(void);
int			get_current_folder_length(void);
/*
** utils
*/
void		ft_clean_prompt(void);
void		string_to_list(char *str);

#endif
