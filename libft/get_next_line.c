/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:09:29 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/21 15:35:02 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_line(char *s)
{
	while (s && *s)
	{
		if (*s++ == '\n')
			return (1);
	}
	return (0);
}

char	*ft_findline(char *s)
{
	int		i;
	char	*tab;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (!(tab = malloc(sizeof(char) * (i + 1))))
	{
		if (s)
			free(s);
		return (NULL);
	}
	ft_strlcpy(tab, s, i + 1);
	return (tab);
}

char	*ft_resize(char *s, char *line)
{
	int		i;
	char	*tab;

	if (!line)
		return (NULL);
	i = ft_strlen(line);
	if (s && *s && *(s += i) == '\n')
	{
		s++;
		if (!(tab = malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		ft_strlcpy(tab, s, ft_strlen(s) + 1);
		free(s - i - 1);
	}
	else
	{
		if (!(tab = malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		ft_strlcpy(tab, s, ft_strlen(s) + 1);
		if (s)
			free(s - i);
	}
	return (tab);
}

int		get_next_line(int fd, char **line)
{
	static char	*s;
	char		*buffer;
	int			j;

	j = -1;
	if (fd < 0 || read(fd, NULL, 0) < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_line(s) && ((j = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[j] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free(buffer);
	*line = ft_findline(s);
	if ((!(s = ft_resize(s, *line))) || !*line)
		return (-1);
	if (j == 0 && (ft_strlen(s) == 0))
	{
		free(s);
		s = NULL;
		return (0);
	}
	return (1);
}
