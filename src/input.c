/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:02:23 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/24 10:10:09 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	get_input(t_pip *s)
{
	char	*ss;
	int	in;

	in = ft_open(&s->fdi, ".here_doc", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (in == -1)
	{
		close(s->fdi);
		err("Error file\nError", 1);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		if (get_next_line(0, &ss) < 0)
			write(2, "erreur gnl", 10);
		if (!ft_strcmp(ss, s->data.argv[2]))
			break ;
		write(s->fdi, ss, ft_strlen(ss));
		write(s->fdi, "\n", 1);
	}	
	close(s->fdi);
	in = ft_open(&s->fdi, ".here_doc", O_RDONLY, 0);	
	if (in == -1)
	{
		close(s->fdi);
		unlink(".here_doc");
		err("Error file\nError", 1);
	}
}
