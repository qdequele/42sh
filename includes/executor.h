/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:24:26 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/29 17:24:18 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include <ft_sh.h>
# include <parser.h>

# define GET_JOB_LINKER(x) ((t_job *)x->content)->linker

void			exec_job_list(t_list *job_list);
void			prepare_job(t_job *j);
void			launch_job(t_job *j, int foreground);
void			put_job_in_background(t_job *j, int cont);
void			put_job_in_foreground(t_job *j, int cont);
void			wait_for_job(t_job *j);
int				job_is_completed(t_job *j);
int				job_is_stopped(t_job *j);

void			launch_process(t_process *p, pid_t pgid, int foreground);
void			launch_process_builtin(t_process *p);
int				update_process_status(t_job *j, pid_t pid, int status);
int				is_job_success(t_job *j);

t_job			*find_job_by_gpid(t_list *job_list, pid_t gpid);
t_job			*find_job_by_pid(t_list *job_list, pid_t pid);
int				find_job_index(pid_t gpid);
t_job			*find_job_by_index(int index);

int				update_process_status_by_pid(t_list *process_list,
					pid_t pid, int status);
void			update_job_status_by_pid(t_list *job_list,
					pid_t pid, int status);
void			update_job_status(void);
void			put_job_info(t_job *j, int index);
int				get_job_exit_code(t_job *j);
int				get_job_raw_exit_code(t_job *j);
void			log_job_exit_signal(t_job *j);

#endif
