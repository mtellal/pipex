/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:50 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/23 10:58:41 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_pip *s, char **argv)
{
	s->fdi = open(argv[1], O_RDONLY, 0);
	s->fdo = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (s->fdi == -1 || s->fdo == -1)
	{
		if (s->fdi == -1 && s->fdo != -1)
			close(s->fdo);
		else if (s->fdo == -1 && s->fdi != -1)
			close(s->fdi);
		err("", 1, 1);
	}
	ft_pipe(s, s->pipe);
	fill_args(s, argv);
}

void	fils(t_pip s, char **env)
{
	int	fd;

	fd = 0;
	ft_dup2(&s, 1, fd);
	ft_dup2(&s, s.fdi, 0);
	ft_dup2(&s, s.pipe[1], 1);
	close_fd(s.fdi, s.fdo, s.pipe[0], s.pipe[1]);
	if (execve(s.cmd1, s.arg1, env) == -1)
	{
		free_tab(s.arg1);
		free_tab(s.arg2);
		free(s.cmd1);
		free(s.cmd2);
		err("command not found", 0, fd);
	}
}

void	pere(t_pip s, char **env)
{
	int	fd;

	fd = 0;
	ft_dup2(&s, 1, fd);
	ft_dup2(&s, s.fdo, 1);
	ft_dup2(&s, s.pipe[0], 0);
	close_fd(s.fdi, s.fdo, s.pipe[0], s.pipe[1]);
	if (execve(s.cmd2, s.arg2, env) == -1)
	{
		free_tab(s.arg1);
		free_tab(s.arg2);
		free(s.cmd1);
		free(s.cmd2);
		err("command not found", 0, fd);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pip	s;
	pid_t	f;

	errno = 0;
	if (argc == 5)
	{
		init(&s, argv);
		command(s.arg1[0], &s, env, 0);
		command(s.arg2[0], &s, env, 1);
		f = fork();
		if (f == 0)
			fils(s, env);
		else
		{
			wait(NULL);
			pere(s, env);
		}
	}
	else
		err("Erreur: probleme d'arguments", 0, 1);
	return (0);
}
