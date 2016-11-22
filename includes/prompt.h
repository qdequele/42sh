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

# define UP (b[0] == 27 && b[1] == 91 && b[2] == 65)
# define S_UP (b[0] == 27 && b[1] == 27 && b[2] == 91 && b[3] == 65)
# define DOWN (b[0] == 27 && b[1] == 91 && b[2] == 66)
# define S_DOWN (b[0] == 27 && b[1] == 27 && b[2] == 91 && b[3] == 66)
# define RIGHT (b[0] == 27 && b[1] == 91 && b[2] == 67)
# define S_RIGHT (b[0] == 27 && b[1] == 27 && b[2] == 91 && b[3] == 67)
# define FN_RIGHT (b[0] == 27 && b[1] == 91 && b[2] == 70)
# define LEFT (b[0] == 27 && b[1] == 91 && b[2] == 68)
# define S_LEFT (b[0] == 27 && b[1] == 27 && b[2] == 91 && b[3] == 68)
# define FN_LEFT (b[0] == 27 && b[1] == 91 && b[2] == 72)
# define BACK_SPACE (b[0] == 127 && b[1] == 0 && b[2] == 0)
# define DEL (b[0] == 27 && b[1] == 91 && b[2] == 51 && b[3] == 126)
# define ENTER (b[0] == 10 && b[1] == 0 && b[2] == 0)
# define TAB (b[0] == 9 && b[1] == 0 && b[2] == 0)
# define HOME (b[0] == 27 && b[1] == 91 && b[2] == 72)
# define END (b[0] == 27 && b[1] == 91 && b[2] == 70)
# define IGNORE_1 (b[0] == 27 && b[1] == 91 && b[2] == 49)
# define CTRL_D (b[0] == 4 && b[1] == 0 && b[2] == 0)
# define CTRL_L (b[0] == 12 && b[1] == 0 && b[2] == 0)
# define ALT_C (b[0] == -61 && b[1] == -89 && b[2] == 0)
# define ALT_V (b[0] == -30 && b[1] == -120 && b[2] == -102)
# define ALT_X (b[0] == -30 && b[1] == -119 && b[2] == -120 && b[3] == 0)
# define ALT_B (b[0] == -30 && b[1] == -120 && b[2] == -85 && b[3] == 0)
# define SEEK_HISTORY (b[0] == 33 && b[1] == 0 && b[2] == 0)

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
	int			i_pos;
	int			p_pos;
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

void			*get_actions_normal(void);
void			*get_actions_copy(void);
void			*get_actions_heredoc(void);
void			*get_actions_quote(void);
t_status		prompt_find_function(char *b);
t_prompt		*init_prompt(void);
void			add_history(char *line);
/*
** Action - Common
*/
void			put_specific_char(char c, int fd);
void			add_char(char c);
void			inser_char(char c);
t_status		action_insert_char(char *b);
t_status		action_delete_char(char *b);
t_status		action_delete_next_char(char *b);
t_status		action_move_up(char *b);
t_status		action_move_down(char *b);
t_status		action_move_left(char *b);
t_status		action_move_right(char *b);
t_status		action_move_start(char *b);
t_status		action_move_end(char *b);
t_status		action_move_next_word(char *b);
t_status		action_move_last_word(char *b);
t_status		action_exec_cmd(char *b);
t_status		action_ignore_input(char *b);
t_status		action_quit(char *b);
t_status		action_clear(char *b);
/*
** Action - Copy
*/
void			free_copy(void);
t_status		action_copy_quit(char *b);
t_status		action_copy(char *b);
t_status		main_action_copy(char *b);
t_status		action_cut(char *b);
t_status		action_free(char *b);
t_status		action_paste(char *b);
/*
** Action - Normal
*/
int				get_normal_prompt_length(void);
char			*read_normal_input(void);
char			*action_seek_to_history(char *cmds);
t_status		action_autocomplete(char *b);
t_status		action_history_up(char *b);
t_status		action_history_down(char *b);
void			save_history(void);
void			load_history(void);
void			reset_history(void);
void			save_vars(void);
void			load_vars(void);
void			reset_vars(void);
/*
** Action - Quote
*/
char			display_quote_error(char c);
int				print_error(char flag);
int				quote_close(char *str, char c);
void			read_quote_input(char quote);
int				check_quote(char *line);
int				get_quote_prompt_length(char c);
t_status		action_exec_cmd(char *b);
/*
** Utils
*/
void			clean_prompt(void);
void			clean_last_x_char(int i);
void			free_char(void *content, size_t size);
void			free_input(void);
int				sort_by_lexycography(t_list *node);
void			string_to_list(char *str);
char			*list_to_string(void);
char			**list_to_tab(t_list *list);
void			erase_one_char(void);
void			erase_x_chars(int x);
void			delete_one_char(void);
void			delete_x_chars(int x);
void			get_cmd_list(t_list **possibilities, char *last_word);
void			get_builtins_list(t_list **possibilities, char *last_word);
void			get_files_list_one(t_list **possibilities, char *path,
	char *name, char *cmd_start);
void			get_files_list(t_list **possibilities, char *last_word);
void			reset_autocomplete_possibilities(void);
char			*before_last_word(char *str, int c);
char			*get_last_word(char *str, int c);
void			utils_move_up(void);
void			utils_move_down(void);
void			utils_move_left(void);
void			utils_move_right(void);
void			utils_move_start(void);
void			utils_move_end(void);
void			utils_move_max_top(void);
void			utils_move_max_bottom(void);
void			print_eol(void);

#endif
