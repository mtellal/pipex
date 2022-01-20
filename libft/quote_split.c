/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:38:27 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/20 10:47:17 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	quote_block(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 39 || s[i] == 34)
			return (i);
		i++;
	}
	return (0);
}

char	**add_tab(char **tab, char *s)
{
	char	**t;
	int		i;

	i = 0;
	t = malloc(sizeof(char) * (len_tab(tab) + 2));
	while (tab && tab[i])
	{
		t[i] = tab[i];
		i++;
	}
	t[i] = s;
	t[++i] = NULL;
	return (t);
}

char	**quote_split(char *argv, int index)
{
	char	**tab;
	char	**tab2;
	char	*sub;

	sub = malloc(sizeof(char) * index + 1);
	ft_strlcpy(sub, argv, index);
	tab = ft_split(sub, ' ');
	free(sub);
	sub = malloc(sizeof(char) * ft_strlen(argv + index) + 2);
	ft_strlcpy(sub, argv + index + 1, ft_strlen(argv + index) - 1);
	tab2 = add_tab(tab, sub);
	return (tab2);
}

void	fill_args(t_pip *s, char **argv)
{
	int	arg1;
	int	arg2;

	arg1 = quote_block(argv[2]);
	arg2 = quote_block(argv[3]);
	if (arg1 || arg2)
	{
		if (arg1)
			s->arg1 = p_q(quote_split(argv[2], arg1));
		if (arg2)
			s->arg2 = p_q(quote_split(argv[3], arg2));
	}
	if (!arg1 || arg2)
	{
		if (!arg1)
			s->arg1 = ft_split(argv[2], ' ');
		if (!arg2)
			s->arg2 = ft_split(argv[3], ' ' );
	}
}
