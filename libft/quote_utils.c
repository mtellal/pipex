/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:07:58 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/20 11:21:23 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rm_quote(char *s)
{
	int		i;
	char	*ss;
	char	*sub;
	char	*sub2;

	ss = NULL;
	i = quote_block(s);
	if (i)
	{
		sub = malloc(sizeof(char) * ft_strlen(s));
		if (!sub)
			return (0);
		ft_strlcpy(sub, s, i + 1);
		sub2 = malloc(sizeof(char) * ft_strlen(s + i) + 1);
		if (!sub2)
			return (0);
		ft_strlcpy(sub2, s + i + 1, ft_strlen(s + i) + 1);
		ss = ft_strjoin(sub, sub2);
		free(sub);
		free(sub2);
		free(s);
	}
	else
		return (s);
	return (ss);
}

char	**p_q(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		tab[i] = rm_quote(tab[i]);
		i++;
	}
	return (tab);
}
