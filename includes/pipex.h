/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:38:51 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/22 10:23:22 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

#include "libft.h"

typedef struct s_data {
	int	argc;
	char	**argv;
	char	**env;
}		t_data;

typedef struct s_pip {
        int             fdi;
        int             fdo;
        int             **pipe;
        char    ***arg;
	char	**cmd;

	//tab de forks pas forcement necessaire 
	pid_t	*forks;
	t_data	data;
}               t_pip;

/////		LOOP_COMMANDS		/////

void    create_processes(int argc, int i, t_pip *s, char **env);
void	loop_commands(int argc, t_pip *s, char **env);

/////		PROCESSES		/////

void	fill_commands(t_pip *s, int nbc);

void    launch_processes(int argc, int i, t_pip *s);
void    process(t_pip *s);

void	exec(t_pip *s, char **argv, char **env);
void	err(char *err, int i);
void	command(char *cmd, t_pip *st, int a, char **env);
void	close_fd(int f, int f2, int p, int p2);
void	ft_dup2(t_pip *s, int n, int o);
void	ft_pipe(int i, t_pip *s);
int		ft_dup(t_pip *s, int fd);
void	free_s(t_pip s);
void	ft_malloc(t_pip *s, char **t, size_t m);
void	stop(t_pip *s, char *msg, int i);

int     ft_open(int *fd, char *file, int flags, mode_t mode);


/////		BONUS		/////

void    get_input(t_pip *s);

#endif 
