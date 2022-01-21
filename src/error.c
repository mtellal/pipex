/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:29:47 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/21 19:19:45 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_pip *s, int p)
{
	if (p)
	{
		if ((close(s->pipe[0]) == -1) | (close(s->pipe[1]) == -1))
			perror("Err close pipe:");
	}
	if ((close(s->fdi) == -1) | (close(s->fdo) == -1))
		perror("Err close files:");
}

void	err(char *err, int eno, int fd)
{
	if (eno)
		perror("Erreur");
	ft_putstr_fd(err, fd);
	ft_putstr_fd("\n", fd);
	if ((close(0) == -1) | (close(1) == -1) | (close(2) == -1))
		perror("Err close:");
	exit(0);
}

void    ft_dup2(t_pip *s, int new, int old)
{
        if (dup2(new, old) == -1)
        {
		close_fd(s, 1);
		err("Err dup", 1, 1);
        }
}

int	ft_open(t_pip *s, char *file, int flags, mode_t mode)
{
	int	fd;

	if (mode)
		fd = open(file, flags, mode);
	else
		fd = open(file, flags);
	if (fd == -1)
	{
		close_fd(s, 0);
		err("Err ouverture fichier", 1, 1);
	}
	return (fd);
}

void	ft_pipe(t_pip *s, int	fd[2])
{
	if (pipe(fd) == -1)
	{
		close_fd(s, 1);
		err("Err pipe", 1, 1);
	}
}
