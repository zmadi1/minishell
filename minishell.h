/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:40:50 by zmadi             #+#    #+#             */
/*   Updated: 2020/01/26 13:14:13 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <dirent.h>
# include "Libft/libft.h"
# define DEF          "\033[0m"
# define BOLD         "\033[1m"
# define BLACK        "\033[30m"
# define RED          "\033[31m"
# define GREEN        "\033[32m"
# define BROWN        "\033[33m"
# define BLUE         "\033[34m"
# define MAGENTA      "\033[35m"
# define CYAN         "\033[36m"
# define GRAY         "\033[37m"

void	disp(char *str);
void	ft_strarrayiter(char **arr, void(*dsp)(char *str));
int		get_2darr_len(char **arr2d);
char	**cpy_2darr(char **src);
char	**gimme_2darr_space(int size);
char	*run_exe(char **env, char *exe);
int		exec_builtin(char **av, char ***envcpy);
void	echo_str(char **av, char **env);
int		get_env(char **envcpy, char *key);
void	add_2d_arr_str(char ***env, char **item);
void	rm_2d_arr_str(char ***old, char *item);
void	mk_2d_arr_clean(char ***arr);
int		exec_sh_fun(char **av, char ***envcpy);
char	**get_args(void);
int		just_find_item(char **arr2d, char *item);
int		find_item(char **arr2d, char **item);
int		ft_indexof(char *str, char c);
void	fork_this(char *exe, char **av, char **envcpy);
void	append_var(char ***env, char **item);
void	cd_fun(char ***envcpy, char *av);
void	go_elsewhere(char ***envcpy, char *av);
void	go_home(char ***envcpy);
void	go_find_rel_path(char ***envcpy, char *av);
void	go_dash(char ***envcpy);
void	echo_str(char **av, char **env);
void	echo_f(char **av);
void	echo_x(char **av);
#endif
