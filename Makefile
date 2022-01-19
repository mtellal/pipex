# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 18:22:09 by mtellal           #+#    #+#              #
#    Updated: 2022/01/19 19:06:11 by mtellal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = src/main.c src/command.c src/error.c \
      libft/ft_strjoin.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strncmp.c \
      libft/ft_strlen.c libft/ft_strlcpy.c libft/free_tab.c libft/quote_split.c   

HEADER = -I libft -I src

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o:%.c
	$(GCC) $(CFLAGS) -g -o $@ -c $< $(HEADER) 

$(NAME) : $(OBJ) 
	$(GCC) $(CFLAGS) -g -o $(NAME) $(HEADER) $(OBJ) 

val: $(NAME)
	valgrind --leak-check=full --tool=memcheck --show-reachable=yes --track-fds=yes --errors-for-leak-kinds=all --show-leak-kinds=all --trace-children=yes ./pipex main.c cat wc output

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
