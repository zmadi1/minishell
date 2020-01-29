/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:38:56 by zmadi             #+#    #+#             */
/*   Updated: 2020/01/26 12:44:25 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int g_xx = 1;

static void		xsig_handler(int x)
{
	ft_putnbr(x);
	(void)x;
	ft_putchar('\n');
	ft_putstr("\033[31m$>\033[0m");
	g_xx = 0;
	exit(1) ;
}

int				main(int ac, char **av, char **env)
{
	char	**args;
	char	**envcp;
	int		run;

	run = 42;
	(void)ac;
	(void)av;
	envcp = NULL;
	args = NULL;
	envcp = cpy_2darr(env);
	signal(SIGINT, xsig_handler);
	while (run)
	{
			ft_putstr("$> ");
		args = get_args();
		run = exec_builtin(args, &envcp);
		mk_2d_arr_clean(&args);
	}
	mk_2d_arr_clean(&envcp);
	return (0);
}
