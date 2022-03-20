/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:59:46 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/20 16:18:02 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_pipes(t_pip *s)
{
	int	i;

	i = 0;
	while (i < s->data.argc - 4)
	{
		close(s->pipe[i][0]);
		close(s->pipe[i][1]);
		i++;
	}
	close(s->fdi);
	close(s->fdo);
}

void	fils0(t_pip s, int p[2])
{
	ft_dup2(&s, s.fdi, 0);
	ft_dup2(&s, p[1], 1);
	close_all_pipes(&s);
	if (execve(s.cmd[0], s.arg[0], s.data.env) == -1)
		write(2, " err fils0 ", 11);
}

void	pere(t_pip s, int p[2], int p2[2], int i)
{
	i++;
	i--;
	write(2, "pere ", 5); 
	ft_dup2(&s, p[0], 0);
	ft_dup2(&s, p2[1], 1);
	close_all_pipes(&s);
	if (execve(s.cmd[i], s.arg[i], s.data.env) == -1)
		write(2, " err pere ", 10);
}

void pere0(t_pip s, int p[2], int i)
{
	write(2, "pere0 ", 6);
	//ft_dup2(&s, s.pipe[1][1], 1);
        ft_dup2(&s, p[0], 0);
	close_all_pipes(&s);
	if (execve(s.cmd[i], s.arg[i], s.data.env) == -1)
		write(2, " err pere0 ", 11);
}

void	process(t_pip *s)
{
	int	i;
	int	j;
	int	nb_pipes;
	/*int	p[2][2];

	pipe(p[0]);
	pipe(p[1]);
	*/nb_pipes = s->data.argc - 4;
	i = 0;
	j = 0;
	while (i < nb_pipes)
	{
		printf("fork n %i \n", i);
		s->forks[i] = fork();
		if (s->forks[i] == -1)
			err("error forking", 1);
		if (s->forks[i] == 0)
		{
			if (i == (nb_pipes - 1))
			{
				write(2, "fils", 2);
				fils0(*s, s->pipe[(nb_pipes - 1) - i]);
			}
			else
				pere(*s, s->pipe[i], s->pipe[i + 1], i + 1);
		}
		i++;
	}
	
	pere0(*s, s->pipe[i - 1], i);
	
	while (j < (s->data.argc - 4))
	{
		wait(NULL);
		j++;
	}
}
