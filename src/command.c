/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:58:04 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/20 11:24:56 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**tab_path(char **env, t_pip *s)
{
	char	**tab;
	int		i;

	i = 0;
	while (ft_strncmp("PATH", *env, 4) != 0)
	{
		env++;
		i++;
	}
	if (!i)
	{
		close_fd(s, 1);
		err("probleme avec le PATH", 0);
	}
	tab = ft_split(*env + 5, ':');
	return (tab);
}

int	valid_cmd(char *path, char *cmd)
{
	char	*c;

	c = ft_strjoin(path, "/");
	c = ft_strjoin(c, cmd);
	if (access(c, F_OK && X_OK) == 0)
		return (1);
	return (0);
}

void	command(char *cmd, t_pip *st, char **env, int id)
{
	char	**p;
	char	*s;
	int		i;

	i = 0;
	p = tab_path(env, st);
	while (p[i] && !valid_cmd(p[i], cmd))
		i++;
	if (!p[i])
	{
		free(st->arg1);
		free(st->arg2);
		close_fd(st, 1);
		err("probleme de commande", 1);
	}
	s = ft_strjoin(p[i], "/");
	if (id)
		st->cmd2 = ft_strjoin(s, cmd);
	else
		st->cmd1 = ft_strjoin(s, cmd);
	free(s);
	free_tab(p);
}
