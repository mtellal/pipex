/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:38:51 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/19 14:33:28 by mtellal          ###   ########.fr       */
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

typedef struct s_pip {	
	int		fdi;
	int		fdo;
	int		pipe[2];
	char	**arg1;
	char	**arg2;
	char	*cmd1;
	char	*cmd2;
}			t_pip;

void	exec(char **argv, char **env);
void	err(char *err, int i);
void	command(char *cmd, t_pip *st, char **env, int id);

#endif 
