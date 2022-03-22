# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 18:22:09 by mtellal           #+#    #+#              #
#    Updated: 2022/03/21 15:30:24 by mtellal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = src/main.c src/error.c src/error_utils.c src/loop_commands.c \
	parse/command.c \
	libft/ft_strjoin.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strncmp.c \
	libft/ft_strlen.c libft/ft_strlcpy.c libft/free_tab.c libft/quote_split.c libft/quote_utils.c \
	libft/ft_strdup.c libft/get_next_line.c libft/get_next_line_utils.c \
	bonus/input.c

HEADER = -I includes

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
