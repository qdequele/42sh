/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 23:49:18 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/07 13:02:48 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <ft_sh.h>
# include <lexer.h>

typedef enum			e_job_linker
{
	LINK_THEN,
	LINK_AND,
	LINK_OR,
	LINK_TO_BACKGROUND
}						t_job_linker;

typedef struct			s_io_channel
{
	int					fd;
	char				to_close;
	char				aggr;
	char				dead_end;
	int					open_mode;
	char				*target;
}						t_io_channel;

typedef struct			s_process
{
	char				**argv;
	pid_t				pid;
	int					status;
	char				completed;
	char				stopped;
	t_io_channel		stdio[3];
}						t_process;

typedef struct			s_job
{
	char				*command;
	t_list				*process_list;
	pid_t				pgid;
	char				notified;
	t_job_linker		linker;
}						t_job;

t_list					*token_list_to_job_list(t_list *token_list);
t_list					*parse_job(t_list *token_split);
t_list					*parse_process(t_token *t);
int						parser_assert_linker(t_token *t);
int						parser_assert_pipe(t_token *t);
int						parser_assert_cmd(t_token *t);
char					**parse_cmd_argv(t_process *p, char *cmd);
int						parse_io_channel(t_process *p, char **split);
int						is_aggregate_fd(char *redir);
int						aggreagate_fd(t_process *p, char *redir);
int						get_redir_channel(char *redir);
int						count_target_length(t_process *p, char **sp,
							char sy, int (*p_fn)(t_process *, int, char *));
void					del_job(void *job_raw, size_t job_size);
void					del_process(void *raw_process, size_t process_size);
char					*construct_job_command(t_list *process_list);
char					*get_cmd_env(char *cmd, char *var_raw);
int						parse_heredoc_redir(t_process *p, int channel,
							char *target);
char					*ft_str_replace_var(char *src, char *var, int *i);
int						ft_is_var(char c);
char					*replace_vars(char *str);

#endif
