/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:59:46 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/18 20:15:59 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    fils0(t_pip s, char **env)
{
        ft_dup2(&s, s.fdi, 0);
        ft_dup2(&s, s.pipe[0][1], 1);
        //close_fd(0, s.fdo, s.pipe[0], 0);
        if (execve(s.cmd[0], s.arg[0], env) == -1)
        {
                //free_s(s);
                err("command not found", 0);
        }
}

void    pere(t_pip s, char **env, int i)
{
        ft_dup2(&s, s.pipe[i][1], 1);
        ft_dup2(&s, s.pipe[i - 1][0], 0);
        //close_fd(s.fdi, s.fdo, s.pipe[0], s.pipe[1]);
        if (execve(s.cmd[i], s.arg[i], env) == -1)
        {
                //free_s(s);
                err("command not found", 0);
        }
}

void    pere0(t_pip s, char **env, int i)
{
        ft_dup2(&s, s.fdo, 1);
        ft_dup2(&s, s.pipe[i - 1][0], 0);
        //close_fd(s.fdi, s.fdo, s.pipe[0], s.pipe[1]);
        if (execve(s.cmd[i], s.arg[i], env) == -1)
        {
                //free_s(s);
                err("command not found", 0);
        }
	exit(0);
}

void	launch_processes(int argc, int i, t_pip *s)
{
	if (i < (argc - 3 - 1))
	{
		s->forks[i] = fork();
		if (s->forks[i] == -1)
			stop(s, 0, 1);
		if (s->forks[i] == 0)
		{
			i++;
			launch_processes(argc, i, s);
			if (i == (argc - 3 - 1))
				fils0(*s, s->data.env);
		}
		else
		{
			waitpid(s->forks[i], NULL, 0);
			if (i == 0)
				pere0(*s, s->data.env, (argc - 4) - i);
			else
				pere(*s, s->data.env, (argc - 4) - i);
		}
	}
}


void	process(t_pip *s)
{
	launch_processes(s->data.argc, 0, s);
	exit(0);
}
