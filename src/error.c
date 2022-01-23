/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:29:47 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/23 21:27:06 by mtellal          ###   ########.fr       */
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
	if (tab[0] == -1 || tab[1] == -1)
		perror("Err close files:");
	if (tab[2] == -1 || tab[3] == -1)
		perror("Err close pipe:");
}

void	err(char *err, int eno)
{
	if (eno)
		perror("Erreur");
	if (err && *err)
	{
		ft_putstr_fd(err, 2);
		ft_putstr_fd("\n", 2);
	}
	if ((close(0) == -1) | (close(2) == -1) | (close(1) == -1))
		perror("Err close");
	exit(0);
}

void	ft_dup2(t_pip *s, int new, int old)
{
	if (dup2(new, old) == -1)
		stop(s, "Err dup", 1);
}

void	ft_pipe(t_pip *s, int fd[2])
{
	if (pipe(fd) == -1)
		stop(s, "Err pipe", 1);
}

void	free_s(t_pip s)
{
	free_tab(s.arg1);
	free_tab(s.arg2);
	free(s.cmd1);
	free(s.cmd2);
}
