/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:41:10 by zmadi             #+#    #+#             */
/*   Updated: 2020/01/26 12:42:51 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	go_dash(char ***envcpy)
{
	char	*temp[3];
	int		x;
	char	*buf;

	buf = NULL;
	if (get_env(*envcpy, "OLDPWD") == -1)
		return (ft_putendl("OLDPWD not set"));
	else if ((x = get_env(*envcpy, "PWD")) != -1)
	{
		x = get_env(*envcpy, "OLDPWD");
		chdir(1 + ft_strstr((*envcpy)[x], "="));
		x = get_env(*envcpy, "PWD");
		temp[1] = "OLDPWD";
		temp[2] = 1 + ft_strstr((*envcpy)[x], "=");
		add_2d_arr_str(envcpy, temp);
		temp[1] = "PWD";
		buf = getcwd(buf, 9);
		temp[2] = buf;
		add_2d_arr_str(envcpy, temp);
		ft_strdel(&buf);
		return (ft_putendl(1 + ft_strstr((*envcpy)[x], "=")));
	}
	return (ft_putendl("Something, i don't know what, went horribly wrong"));
}

void	go_find_rel_path(char ***envcpy, char *av)
{
	char	*temp2[3];
	int		x;

	if ((x = get_env(*envcpy, "HOME")) == -1)
		return (ft_putendl("HOME is not set"));
	else
	{
		temp2[2] = ft_strjoin(1 + ft_strstr((*envcpy)[x], "="), 1 + av);
		if (access(temp2[2], F_OK))
			return (ft_putendl("No such directory"));
		ft_strdel(&temp2[2]);
		temp2[1] = "OLDPWD";
		temp2[2] = getcwd(temp2[2], sizeof(temp2[2]));
		add_2d_arr_str(envcpy, temp2);
		ft_strdel(&temp2[2]);
		x = get_env(*envcpy, "HOME");
		temp2[2] = ft_strjoin(1 + ft_strstr((*envcpy)[x], "="), 1 + av);
		chdir(temp2[2]);
		temp2[1] = "PWD";
		add_2d_arr_str(envcpy, temp2);
		return (ft_strdel(&temp2[2]));
	}
	return (ft_putendl("Something went horribly wrong -_-"));
}

void	go_home(char ***envcpy)
{
	char	*temp;
	char	*temp2[3];
	int		x;

	temp = NULL;
	if ((x = get_env(*envcpy, "HOME")) == -1)
		return (ft_putendl("HOME is where the heart is, you don't have 1 -_-"));
	else
	{
		x = get_env(*envcpy, "OLDPWD");
		temp2[1] = "OLDPWD";
		temp = getcwd(temp, sizeof(temp));
		temp2[2] = temp;
		add_2d_arr_str(envcpy, temp2);
		ft_strdel(&temp);
		x = get_env(*envcpy, "HOME");
		chdir(1 + ft_strstr((*envcpy)[x], "="));
		temp2[1] = "PWD";
		temp2[2] = 1 + ft_strstr((*envcpy)[x], "=");
		add_2d_arr_str(envcpy, temp2);
		return ;
	}
	return (ft_putendl("Something went horribly wrong -_-"));
}

void	go_elsewhere(char ***envcpy, char *av)
{
	char *temp[3];
	char *temp2;

	temp2 = NULL;
	if (!access(av, F_OK))
	{
		temp2 = getcwd(temp2, sizeof(temp2));
		temp[1] = "OLDPWD";
		temp[2] = temp2;
		add_2d_arr_str(envcpy, temp);
		chdir(av);
		ft_strdel(&temp2);
		temp2 = getcwd(temp2, sizeof(temp2));
		temp[1] = "PWD";
		temp[2] = temp2;
		add_2d_arr_str(envcpy, temp);
		ft_strdel(&temp2);
		return ;
	}
	return ;
}

void	cd_fun(char ***envcpy, char *av)
{
	if (!av || !ft_strcmp(av, "~") || !ft_strcmp(av, "--"))
		return (go_home(envcpy));
	if (!ft_strcmp("-", av))
		return (go_dash(envcpy));
	else if (av[0] == '~')
		return (go_find_rel_path(envcpy, av));
	else
		return (go_elsewhere(envcpy, av));
	return (ft_putendl("\033[31mundefined failure\033[0m"));
}
