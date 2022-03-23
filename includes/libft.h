/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:26:28 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/22 15:04:53 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

struct s_pip;
typedef struct s_pip t_pip;

char	**ft_split(char *s, char c);
char	*ft_strjoin_free(char *s, char *s2, int f1, int f2);
int		ft_strncmp(const char *s, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	free_tab(char **p);
void	fill_args(t_pip *s, char **argv, int nbc);
int		quote_block(char *s);
char	*rm_quote(char*s);
char	**p_q(char **tab);
char	**fusion_tab(char **t, char **t2);
char	*ft_strdup(char *s);
int             ft_strcmp(const char *s1, const char *s2);
void	ft_malloc(t_pip *s, char **t, size_t m);

#endif
