/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:50 by mtellal           #+#    #+#             */
/*   Updated: 2022/03/23 22:18:43 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*
 *      verifier les opens avec le ft_open ( return int + message d'erreurs etc)
 */

void    ft_open_files(t_pip *s)
{
        t_data  data;

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
        }
}

void    init(t_pip *s, char **argv, int argc)
{
        s->arg = malloc(sizeof(int **) * (argc - 3));
        s->cmd = malloc(sizeof(int *) * (argc - 3));
        if (!s->cmd || !s->arg)
                err("error in allocating t_pip", 0);
        ft_pipe(argc - 4, s);
        fill_args(s, argv, (argc - 3));
        fill_commands(s, (argc - 3));
}

//      probleme 'awk "{$1++}"' ok mais probleme quote_split "awk 'xx'" 
//      unlink here_doc
//      faire plus de tests avec des fonctions plus complexes  

int     main(int argc, char **argv, char **env)
{
        t_pip   s;

        if (argc >= 5)
        {
                s.data.argc = argc;
                s.data.argv = argv;
                s.data.env = env;
                s.err.cmd = 0;
                s.err.args = 0;
                ft_open_files(&s);
                init(&s, s.data.argv, s.data.argc);
                processes(&s);
        }
        else
                err("Erreur: probleme d'arguments", 0);
        return (0);
}

