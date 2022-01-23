/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:50 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/23 21:24:13 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_pip *s, char **argv)
{
	s->fdi = open(argv[1], O_RDONLY, 0);
	s->fdo = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (s->fdi == -1 || s->fdo == -1)
	{
		if (s->fdo != -1)
			close(s->fdo);
		if (s->fdi != -1)
			close(s->fdi);
		err("", 1);
	}
	ft_pipe(s, s->pipe);
	fill_args(s, argv);
}

void	fils(t_pip s, char **env)
{
	ft_dup2(&s, s.fdi, 0);
	ft_dup2(&s, s.pipe[1], 1);
	close_fd(s.fdi, s.fdo, s.pipe[0], s.pipe[1]);
	if (execve(s.cmd1, s.arg1, env) == -1)
	{
		free_s(s);
		err("command not found", 0);
	}
}

void	pere(t_pip s, char **env)
{
	ft_dup2(&s, s.fdo, 1);
	ft_dup2(&s, s.pipe[0], 0);
	close_fd(s.fdi, s.fdo, s.pipe[0], s.pipe[1]);
	if (execve(s.cmd2, s.arg2, env) == -1)
	{
		free_s(s);
		err("command not found", 0);
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
		if (f == -1)
			stop(&s, 0, 1);
		if (f == 0)
			fils(s, env);
		else
		{
			if (wait(NULL) == -1)
				stop(&s, 0, 1);
			pere(s, env);
		}
	}
	else
		err("Erreur: probleme d'arguments", 0);
	return (0);
}
