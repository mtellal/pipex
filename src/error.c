/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:29:47 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/20 11:35:20 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_pip *s, int p)
{
	if (p)
	{
		close(s->pipe[0]);
		close(s->pipe[1]);
	}
	close(s->fdi);
	close(s->fdo);
}

void	err(char *err, int eno)
{
	if (eno)
		perror("Erreur");
	ft_putstr_fd(err, 1);
	ft_putstr_fd("\n", 1);
	close(0);
	close(1);
	close(2);
	exit(0);
}
