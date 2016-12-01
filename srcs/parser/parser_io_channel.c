/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_channel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 04:10:04 by qdequele          #+#    #+#             */
/*   Updated: 2016/12/01 13:23:51 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	parse_truncate_redir(t_process *p, int channel, char *target)
{
	p->stdio[channel].fd = -1;
	p->stdio[channel].open_mode = O_CREAT | O_WRONLY | O_TRUNC;
	p->stdio[channel].to_close = 1;
	if (p->stdio[channel].target)
		free(p->stdio[channel].target);
	p->stdio[channel].target = ft_strdup(target);
	return (0);
}

static int	parse_append_redir(t_process *p, int channel, char *target)
{
	p->stdio[channel].fd = -1;
	p->stdio[channel].open_mode = O_CREAT | O_WRONLY | O_APPEND;
	p->stdio[channel].to_close = 1;
	if (p->stdio[channel].target)
		free(p->stdio[channel].target);
	p->stdio[channel].target = ft_strdup(target);
	return (0);
}

static int	parse_input_redir(t_process *p, int channel, char *target)
{
	p->stdio[channel].open_mode = O_RDONLY;
	p->stdio[channel].fd = -1;
	p->stdio[channel].to_close = 1;
	if (p->stdio[channel].target)
		free(p->stdio[channel].target);
	p->stdio[channel].target = ft_strdup(target);
	return (0);
}

int			parse_io_channel(t_process *p, char **split)
{
	if (is_aggregate_fd(*split))
		return (aggreagate_fd(p, *split));
	if (is_token_redir_append_output(*split))
		return (count_target_length(p, split, '>', &parse_append_redir));
	if (is_token_redir_truncate_output(*split))
		return (count_target_length(p, split, '>', &parse_truncate_redir));
	if (is_token_redir_heredoc(*split))
		return (count_target_length(p, split, '<', &parse_heredoc_redir));
	if (is_token_redir_get_input(*split))
		return (count_target_length(p, split, '<', &parse_input_redir));
	return (1);
}
