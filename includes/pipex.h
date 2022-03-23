/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:38:51 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/23 18:24:23 by mtellal          ###   ########.fr       */
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

typedef struct s_err {
	int	cmd;
	int	args;
}		t_err;

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
	t_data	data;
	t_err	err;
}               t_pip;

/////		PROCESSES		/////

void	close_all_pipes(t_pip *s);
void	processes(t_pip *s);

/////		COMMAND			/////

void	fill_commands(t_pip *s, int nbc);

/////		ERROR 			/////

void	err(char *err, int eno);
void	ft_dup2(t_pip *s, int n, int old);
void	ft_pipe(int i, t_pip *s);
void	free_s(t_pip *s, int pipe, int args, int cmd);

/////		ERROR_UTILS		/////

void	stop(t_pip *s, char *msg, int eno);
int	ft_dup(t_pip *s, int fd);
int	ft_open(int *fd, char *file, int flags, mode_t mode);
void	free_args(t_pip *s);
void	free_cmd(t_pip *s);

/////		INPUT			/////

void	get_input(t_pip *s);

#endif 
