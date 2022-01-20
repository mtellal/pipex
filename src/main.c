/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:50 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/20 11:35:30 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_pip *s, char **argv)
{
	s->fdi = open(argv[1], O_RDONLY);
	s->fdo = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if ((s->fdi == -1) || (s->fdo == -1))
	{
		close_fd(s, 0);
		err("probleme ouverture d'un des fichier", 1);
	}
	if (pipe(s->pipe) == -1)
	{
		close_fd(s, 1);
		err("probleme de pipe", 1);
	}
	fill_args(s, argv);
}

void	fils(t_pip s, char **env)
{
	dup2(s.fdi, 0);
	dup2(s.pipe[1], 1);
	close(s.pipe[0]);
	close(s.pipe[1]);
	close(s.fdo);
	close(s.fdi);
	execve(s.cmd1, s.arg1, env);
}

void	pere(t_pip s, char **env)
{
	dup2(s.fdo, 1);
	dup2(s.pipe[0], 0);
	close(s.pipe[0]);
	close(s.pipe[1]);
	close(s.fdi);
	close(s.fdo);
	execve(s.cmd2, s.arg2, env);
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
		err("Erreur: probleme d'arguments", 0);
	return (0);
}
