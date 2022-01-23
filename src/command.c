/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:58:04 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/23 17:29:04 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**tab_path(char **env, t_pip *s)
{
	char	**tab;
	int		i;

	i = 0;
	while (env && *env && ft_strncmp("PATH", *env, 4) != 0)
	{
		env++;
		i++;
	}
	if (!i)
	{
		close_fd(s->fdi, s->fdo, 0, 0);
		err("probleme avec le PATH", 0);
	}
	tab = ft_split(*env + 5, ':');
	return (tab);
}

int	valid_cmd(char *path, char *cmd)
{
	char	*c;
	char	*s;

	c = ft_strjoin(path, "/", 0, 0);
	s = ft_strjoin(c, cmd, 1, 0);
	if (access(s, F_OK && X_OK) == 0)
	{
		free(s);
		return (1);
	}
	free(s);
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
	if (p[i])
	{
		s = ft_strjoin(p[i], "/", 0, 0);
		if (id)
			st->cmd2 = ft_strjoin(s, cmd, 1, 0);
		else
			st->cmd1 = ft_strjoin(s, cmd, 1, 0);
	}
	else
	{
		if (id)
			st->cmd2 = ft_strdup(cmd);
		else
			st->cmd1 = ft_strdup(cmd);
	}
	free_tab(p);
}
