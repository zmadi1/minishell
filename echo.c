/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:37:57 by zmadi             #+#    #+#             */
/*   Updated: 2020/01/26 12:43:10 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	echo_str(char **av, char **env)
{
	int		i;
	//char	*temp;

	i = 0;
	//temp = NULL;
	if (!av[1])
		return (ft_putchar('\n'));
	if (av[1][0] == '$')
		if ((i = get_env(env, 1 + ft_strstr(av[1], "$"))) != -1)
			return (ft_putendl(1 + ft_strstr(env[i], "=")));
	if (av[1][0] == '"')
		echo_x(av);
	else
	{
		i = 1;
		while (av[i])
		{
			ft_putstr(av[i++]);
			if (i > 1)
				ft_putchar(' ');
		}
		if (!av[i] && i > 1)
			ft_putchar('\n');
	}
	return ;
}

void	echo_x(char **av)
{
	int		i;
	int		x;
	char	*temp;

	temp = NULL;
	i = 1;
	x = get_2darr_len(av);
	if (x == 2)
		return (echo_f(av));
	while (i < (x))
	{
		i == 1 ? ft_putstr(1 + av[i++]) : ft_putstr(av[i++]);
		if (i > 1)
			ft_putchar(' ');
		if (av[i + 1] == NULL)
		{
			temp = ft_strsub(av[i], 0, ft_strlen(av[i]) - 1);
			ft_putendl(temp);
			ft_strdel(&temp);
			break ;
		}
	}
	if (!av[i] && i > 1)
		ft_putchar('\n');
	return ;
}

void	echo_f(char **av)
{
	int i;

	i = 1;
	while (av[1][i] && av[1][i] != '"') {
		ft_putchar(av[1][i++]);
}
	return (ft_putchar('\n'));
}
