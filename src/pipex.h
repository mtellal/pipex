/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:38:51 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/23 21:48:50 by mtellal          ###   ########.fr       */
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
# include "libft.h"

void	exec(t_pip *s, char **argv, char **env);
void	err(char *err, int i);
void	command(char *cmd, t_pip *st, char **env, int id);
void	close_fd(int f, int f2, int p, int p2);
void	ft_dup2(t_pip *s, int n, int o);
void	ft_pipe(t_pip *s, int f[2]);
int		ft_dup(t_pip *s, int fd);
void	free_s(t_pip s);
void	ft_malloc(t_pip *s, char **t, size_t m);
void	stop(t_pip *s, char *msg, int i);

#endif 
