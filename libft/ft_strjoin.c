/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:39:14 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/21 20:18:02 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int f1, int f2)
{
	char	*tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (tab == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = '\0';
	if (f1)
		free(s1);
	if (f2)
		free(s2);
	return (tab);
}
