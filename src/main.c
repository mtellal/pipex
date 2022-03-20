/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:50 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/20 12:25:34 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_pip *s, char **argv, int argc, char **env)
{
	s->fdi = open(argv[1], O_RDONLY, 0);
	s->fdo = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (s->fdi == -1 || s->fdo == -1)
	{
		if (s->fdo != -1)
			close(s->fdo);
		if (s->fdi != -1)
			close(s->fdi);
		err("", 1);
	}
	s->forks = malloc(sizeof(pid_t) * (argc - 3 - 1));
	if (!s->forks || !s->pipe)
		err("error in allocating forks/pipes", 0);
	ft_pipe(argc - 3 - 1, s);
	s->data.argc = argc;
	s->data.argv = argv;
	s->data.env = env;
	s->arg = malloc(sizeof(int **) * (argc - 3));
	s->cmd = malloc(sizeof(int *) * (argc - 3));
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

	errno = 0;
	if (argc >= 5)
	{
		init(&s, argv, argc, env);
		//print_commands_args(s, argc);
		//launch_processes(argc, 0, &s);
		process(&s);
		//create_processes(argc, 0, &s, env);
		//loop_commands(argc - 3 - 1, &s, env);
		/*if (f == 0)
			fils(s, env);
		else
		{
			if (wait(NULL) == -1)
				stop(&s, 0, 1);
			pere(s, env);
		}*/
	}
	else
		err("Erreur: probleme d'arguments", 0);
	return (0);
}
