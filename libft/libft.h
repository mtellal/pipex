/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:26:28 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/18 15:26:30 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

struct s_pip;
typedef struct s_pip t_pip;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s, char *s2, int f1, int f2);
int		ft_strncmp(const char *s, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	free_tab(char **p);
void	fill_args(t_pip *s, char **argv, int nbc);
int		quote_block(char *s);
char	*rm_quote(char*s);
char	**p_q(char **tab);
char	**fusion_tab(char **t, char **t2);
char	*ft_strdup(char *s);

#endif
