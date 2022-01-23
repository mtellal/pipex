/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 10:41:30 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/23 10:59:11 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	unsigned char	*tab;
	unsigned char	*t;

	tab = (unsigned char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (tab == NULL)
		return (NULL);
	t = tab;
	while (*s != '\0')
	{
		*tab++ = *s++;
	}
	*tab = '\0';
	return ((char *)t);
}
