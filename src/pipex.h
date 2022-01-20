/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:38:51 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/20 10:02:02 by mtellal          ###   ########.fr       */
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
void	close_fd(t_pip *s, int i);
#endif 
