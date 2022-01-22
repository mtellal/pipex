/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:29:47 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/22 18:01:41 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int fdi, int fdo, int p1, int p2)
{
	int	tab[4];

	if (fdi)
		tab[0] = close(fdi);
	if (fdo)
		tab[1] = close(fdo);
	if (p1)
		tab[2] = close(p1);
	if (p2)
		tab[3] = close(p2);
	if ( tab[0] == -1 || tab[1] == -1)
		perror("Err close files:");
	if (tab[2] == -1 || tab[3] == -1)
		perror("Err close pipe:");
}

void	err(char *err, int eno, int fd)
{
	if (eno)
		perror("Erreur");
	ft_putstr_fd(err, fd);
	ft_putstr_fd("\n", fd);
	close(fd);
	if ((close(0) == -1) | (close(1) == -1) | (close(2) == -1) | (close(fd) == -1))
		perror("Err close:");
	exit(0);
}

void    ft_dup2(t_pip *s, int new, int old)
{
        if (dup2(new, old) == -1)
        {
		close_fd(s->fdi, s->fdo, s->pipe[0], s->pipe[1]);
		err("Err dup", 1, 1);
        }
}

void	ft_pipe(t_pip *s, int	fd[2])
{
	if (pipe(fd) == -1)
	{
		close_fd(s->fdi, s->fdo, 0, 0);
		err("", 1, 1);
	}
}
