/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/30 17:48:17 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H
# include <ft_sh.h>

# define UP ((buf[0] == 27 && buf[1] == 91 && buf[2] == 65))

# define SHIFT_UP ((buf[0] == 27 && buf[1] == 27 && SUP2))
# define SUP2 buf[2] == 91 && buf[3] == 65

# define SHIFT_MAJ_UP ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && SMUP2))
# define SMUP2 buf[3] == 59 && buf[4] == 49 && buf[5] == 48 && buf[7] == 65

# define DOWN ((buf[0] == 27 && buf[1] == 91 && buf[2] == 66))

# define SHIFT_DOWN ((buf[0] == 27 && buf[1] == 27 && SD2))
# define SD2 buf[2] == 91 && buf[3] == 66

# define SHIFT_MAJ_DOWN ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && SMD))
# define SMD buf[3] == 59 && buf[4] == 49 && buf[5] == 48 && buf[7] == 66

# define RIGHT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 67))

# define SHIFT_RIGHT ((buf[0] == 27 && buf[1] == 27 && SR))
# define SR buf[2] == 91 && buf[3] == 67

# define FN_RIGHT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 70))

# define SHIFT_MAJ_RIGHT ((buf[0] == 27 && buf[1] == 91 && SFR && SFR2))
# define SFR buf[2] == 49 && buf[3] == 59 && buf[4] == 49 && buf[5] == 48
# define SFR2 buf[6] == 67 && buf[7] == 0

# define LEFT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 68))

# define SHIFT_LEFT ((buf[0] == 27 && buf[1] == 27 && SL))
# define SL buf[2] == 91 && buf[3] == 68

# define FN_LEFT ((buf[0] == 27 && buf[1] == 91 && buf[2] == 72))

# define SHIFT_MAJ_LEFT ((buf[0] == 27 && buf[1] == 91 && SML && SML2))
# define SML buf[2] == 49 && buf[3] == 59 && buf[4] == 49 && buf[5] == 48
# define SML2 buf[6] == 68 && buf[7] == 0

# define BACK_SPACE ((buf[0] == 127 && buf[1] == 0 && buf[2] == 0))

# define DELETE ((buf[0] == 27 && buf[1] == 91 && DELETE2))
# define DELETE2 buf[2] == 51 && buf[3] == 126

# define ENTER ((buf[0] == 10 && buf[1] == 0 && buf[2] == 0))
# define TAB ((buf[0] == 9 && buf[1] == 0 && buf[2] == 0))

# define HOME ((buf[0] == 27 && buf[1] == 91 && buf[2] == 72))
# define END ((buf[0] == 27 && buf[1] == 91 && buf[2] == 70))
# define IGNORE_1 ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49))
# define CTRL_D ((buf[0] == 4 && buf[1] == 0 && buf[2] == 0))

# define ALT_C (buf[0] == -61 && buf[1] == -89 && buf[2] == 0)
# define ALT_V (buf[0] == -30 && buf[1] == -120 && buf[2] == -102)
# define ALT_X (buf[0] == -30 && buf[1] == -119 && ALT_X2)
# define ALT_X2 buf[2] == -120 && buf[3] == 0
# define ALT_B (buf[0] == -30 && buf[1] == -120 && ALT_B2)
# define ALT_B2 buf[2] == -85 && buf[3] == 0

# define SEEK_HISTORY ((buf[0] == 33 && buf[1] == 0 && buf[2] == 0))

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
	int			i_copy;
	int			flag_cut;
	char		*str_cpy;
	int			end_cpy;
	int			p_length;
	int			copy_mode;
	int			cut_len;
	char		quote_type;
	int			quote_number;
}				t_prompt;

void			get_cmd_list(t_list **possibilities, char *last_word);
void			get_builtins_list(t_list **possibilities, char *last_word);
void			get_files_list(t_list **possibilities, char *last_word);
char			*read_input(void);
t_status		action_autocomplete(char *buf);
t_status		action_insert_char(char *buf);
t_status		action_delete_char(char *buf);
t_status		action_delete_next_char(char *buf);
t_status		action_exec_cmd(char *buf);
t_status		action_ignore_input(char *buf);
t_status		action_insert_char(char *buf);
t_status		action_quit(char *buf);
t_status		action_history_up(char *buf);
t_status		action_history_down(char *buf);
char			*action_seek_to_history(char *buf);
t_status		action_move_up(char *buf);
t_status		action_move_down(char *buf);
t_status		action_move_left(char *buf);
t_status		action_move_right(char *buf);
t_status		action_move_next_word(char *buf);
t_status		action_move_last_word(char *buf);
t_status		action_move_start(char *buf);
t_status		action_move_end(char *buf);
t_status		action_move_max_top(char *buf);
t_status		action_move_max_bottom(char *buf);
t_status		prompt_find_function(char *buf);
void			*get_actions_normal(void);
void			*get_actions_copy(void);
void			*get_actions_autocomplete(void);
void			*get_actions_history(void);
t_status		action_copy_quit(char *buf);
t_status		main_action_copy(char *buf);
t_status		action_copy(char *buf);
t_status		action_paste(char *buf);
t_status		action_copy(char *buf);
t_status		action_cut(char *buf);
t_status		action_free(char *buf);
t_prompt		*init_prompt(void);
char			*get_current_folder(void);
int				get_current_folder_length(void);
void			clean_prompt(void);
void			string_to_list(char *str);
char			*list_to_string(void);
void			free_char(void *content, size_t size);
void			print_eol(void);
void			inser_char(char c);
void			erase_one_char(void);
void			erase_x_chars(int x);
void			delete_one_char(void);
void			delete_x_chars(int x);
void			utils_move_up(void);
void			utils_move_down(void);
void			utils_move_left(void);
void			utils_move_right(void);
void			utils_move_start(void);
void			utils_move_end(void);
void			utils_move_max_top(void);
void			utils_move_max_bottom(void);
int				check_quote(char *str);
void			parse_quotes(char quote);
int				print_error(char flag);
char			display_quote_error(char c);
int				quote_close(char *str, char c);
char			*before_last_word(char *str, int c);
char			*get_last_word(char *str, int c);
int				sort_by_lexycography(t_list *node);
void			clean_last_x_char(int i);
char			**list_to_tab(t_list *list);

#endif
