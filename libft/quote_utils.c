/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:07:58 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/22 16:26:12 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**fusion_tab(char **t1, char **t2)
{
	char	**tab;
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (t1 && t1[i])
		i++;
	while (t2 && t2[i])
		i++;
	tab = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (t1 && t1[i])
	{
	       tab[i] = t1[i];
		i++;
	}
	while (t2 && t2[j])
	{
		tab[i++] = t2[j++];
		i++;
		j++;
	}
	tab[i] = NULL;
	return (tab);	
}

