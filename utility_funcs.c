/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:39:50 by zmadi             #+#    #+#             */
/*   Updated: 2020/01/26 13:13:39 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

char *run_exe(char **env, char *exe)
{
	char **path;
	char *temp2;
	char *temp;
	int i;

	temp2 = NULL;
	temp = NULL;
	path = NULL;
	if ((i = get_env(env, "PATH")) == -1)
		return (NULL);
	path = ft_strsplit((ft_strchr(env[i], '=') + 1), ':');
	i = 0;
	while (path[i])
	{
		temp2 = ft_strjoin(path[i], "/");
		temp = ft_strjoin(temp2, exe);
		if (!access(temp, F_OK))
			break;
		ft_strdel(&temp2);
		ft_strdel(&temp);
		i++;
	}
	temp2 ? ft_strdel(&temp2) : 0;
	mk_2d_arr_clean(&path);
	return (temp);
}

void fork_this(char *exe, char **av, char **envcpy)
{
	pid_t x;
	int status;

	x = fork();
	if (x > 0)
		waitpid(x, &status, 0 | WUNTRACED);
	if (x == 0)
	{
		if (execvp(av[0], av) == -1)
		{
			perror("lsh");
			exit(EXIT_FAILURE);
		}
		return;
	}
	else if (x < 0)
	{
		if (execve(av[0][0] == '/' ? av[0] : exe, av, envcpy) == -1)
		{
			ft_putstr_fd(RED, 2);
			ft_putstr_fd(av[0], 2);
			ft_putendl_fd(" No such file or directory\033[0m", 2);
		}
	}
	else
		return;

		//ft_putendl_fd("\033[31mfork failed\033[0m", 2);
	return;
}

int exec_sh_fun(char **av, char ***envcpy)
{
	char *xecute;

	xecute = NULL;
	if (!ft_strcmp("ls", av[0]))
	{
		xecute = run_exe(*envcpy, av[0]);
		fork_this(xecute, av, *envcpy);
	}
	else if (!ft_strcmp("emacs", av[0]))
	{
		xecute = run_exe(*envcpy, av[0]);
		fork_this(xecute, av, *envcpy);
	}
	else
	{
		xecute = run_exe(*envcpy, av[0]);
		fork_this(xecute, av, *envcpy);
	}
	// else
	// 	ft_putendl_fd("\033[31mno such command\033[0m", 2);
	xecute ? ft_strdel(&xecute) : 0;
	return (42);
}

char **get_args(void)
{
	char *line;
	char **args;
	char *temp;
	char *new;

	temp = NULL;
	args = NULL;
	line = NULL;
	if (get_next_line(0, &line) == 1)
		temp = line ? ft_strdup(line) : NULL;
	line ? ft_strdel(&line) : 0;
	if (temp != NULL)
	{
		new = ft_epur(temp);
		ft_strdel(&temp);
		temp = ft_strtrim(new);
		ft_strdel(&new);
		args = ft_strsplit(temp ? temp : new, ' ');
		ft_strdel(&temp);
	}
	return (args);
}
