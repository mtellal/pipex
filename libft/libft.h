/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:26:28 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/19 18:48:53 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_pip {
        int             fdi;
        int             fdo;
        int             pipe[2];
        char    **arg1;
        char    **arg2;
        char    *cmd1;
        char    *cmd2;
}                       t_pip;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s, char const *s2);
int		ft_strncmp(const char *s, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	free_tab(char **p);
void    fill_args(t_pip *s, char **argv);

#endif
