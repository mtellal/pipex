/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:26:28 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/23 10:42:44 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_pip {
	int		fdi;
	int		fdo;
	int		pipe[2];
	char	**arg1;
	char	**arg2;
	char	*cmd1;
	char	*cmd2;
}		t_pip;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s, char *s2, int f1, int f2);
int		ft_strncmp(const char *s, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	free_tab(char **p);
void	fill_args(t_pip *s, char **argv);
int		quote_block(char *s);
char	*rm_quote(char*s);
char	**p_q(char **tab);
char	**fusion_tab(char **t, char **t2);
char	*ft_strdup(char *s);

#endif
