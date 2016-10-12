/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:32:52 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H
# include <libft.h>
# include <sys/ioctl.h>
# include <signal.h>

/*
** Signal.c
*/
void	signal_handler(int i);
void	init_signals(void);
/*
** Signal_handler.c
*/
void	signal_resize_screen(int i);
void	signal_exit(int i);
void	signal_background(int i);
void	signal_foreground(int i);

#endif
