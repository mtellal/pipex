/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:50 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/22 10:49:32 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*
 *	verifier les opens avec le ft_open ( return int + message d'erreurs etc)
 */

void	ft_open_files(t_pip *s)
{
	t_data	data;

	data = s->data;
	if (!ft_strcmp(data.argv[1], "here_doc"))
	{
		ft_open(&s->fdo, data.argv[data.argc - 1], O_CREAT | O_RDWR | O_APPEND, 0666);
		get_input(s);
		s->data.argc--;
		s->data.argv++;
	}
	else
	{
		ft_open(&s->fdi, data.argv[1], O_RDONLY, 0);
		ft_open(&s->fdo, data.argv[data.argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
		//s->fdi = open(data.argv[1], O_RDONLY);
		//s->fdo = open(data.argv[data.argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	}
}

void	init(t_pip *s, char **argv, int argc)
{
	s->forks = malloc(sizeof(pid_t) * (argc - 4));
	s->arg = malloc(sizeof(int **) * (argc - 3));
	s->cmd = malloc(sizeof(int *) * (argc - 3));
	if (!s->forks || !s->cmd || !s->arg)
		err("error in allocating t_pip", 0);
	ft_pipe(argc - 4, s);
	fill_args(s, argv, (argc - 3));
	fill_commands(s, (argc - 3));
}

void	print_commands_args(t_pip s, int argc)
{
	int     i = 0;
                while (i < (argc - 3))
                {
                        printf(" cmd[%i] = %s \n",i, s.cmd[i]);
                        i++;
                }
                i = 0;
                while (i < (argc - 3))
                {
                        int j = 1;
			printf(" %s	", s.arg[i][0]);
                        printf("args = ");
			while (s.arg[i][j])
                        {
                                printf("%s ", s.arg[i][j]);
                                j++;
                        }
                        printf("\n");
			i++;
                }
}


//	probleme 'awk "{$1++}"' ok mais probleme quote_split "awk 'xx'" 
//	probleme lorsque 2 "cmd xx", ex "cat in" "grep x"

int	main(int argc, char **argv, char **env)
{
	t_pip	s;

	if (argc >= 5)
	{
		s.data.argc = argc;
		s.data.argv = argv;
		s.data.env = env;
		ft_open_files(&s);
		init(&s, s.data.argv, s.data.argc);
		process(&s);
	}
	else
		err("Erreur: probleme d'arguments", 0);
	return (0);
}
