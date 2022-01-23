/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:06:39 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/23 21:28:58 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	stop(t_pip *s, char *msg, int eno)
{
	close_fd(s->fdi, s->fdo, s->pipe[0], s->pipe[1]);
	if (eno && msg && *msg)
		err(msg, 1);
	if (eno)
		err("", 1);
	else
		err("", 0);
}

int	ft_dup(t_pip *s, int fd)
{
	int	f;

	f = dup(fd);
	if (f == -1)
		stop(s, "Err dup", 1);
	return (f);
}
