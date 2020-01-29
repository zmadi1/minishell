/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:44:02 by zmadi             #+#    #+#             */
/*   Updated: 2020/01/26 12:44:08 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int		get_env(char **envcpy, char *key)
{
	int i;

	i = 0;
	while (envcpy[i])
	{
		if (!ft_strncmp(envcpy[i], key, ft_strlen(key)))
			return (i);
		i++;
	}
	return (-1);
}

int		find_item(char **arr2d, char **item)
{
	int		i;
	char	*temp;
	int		index;

	temp = NULL;
	i = 0;
	if ((index = ft_indexof(item[1], '=')) != -1)
		temp = ft_strsub(item[1], 0, index);
	else
		temp = ft_strdup(item[1]);
	i = get_env(arr2d, temp);
	ft_strdel(&temp);
	return (i);
}

void	append_var(char ***env, char **item)
{
	char	**new;
	int		j;
	int		i;
	char	*temp;

	temp = NULL;
	new = NULL;
	j = get_2darr_len(*env);
	new = gimme_2darr_space(j + 2);
	i = -1;
	while ((*env)[++i])
		new[i] = ft_strdup((*env)[i]);
	if ((j = ft_indexof(item[1], '=')) != -1)
		new[i++] = ft_strdup(item[1]);
	else
	{
		temp = ft_strjoin(item[1], "=");
		new[i++] = ft_strjoin(temp, item[2]);
		ft_strdel(&temp);
	}
	new[i] = NULL;
	mk_2d_arr_clean(env);
	*env = new;
	return ;
}

void	add_2d_arr_str(char ***env, char **item)
{
	int		i;
	char	*temp;

	temp = NULL;
	if ((i = find_item(*env, item)) != -1)
	{
		ft_strdel(&(*env)[i]);
		if ((ft_indexof(item[1], '=')) != -1)
			(*env)[i] = ft_strdup(item[1]);
		else
		{
			temp = ft_strjoin(item[1], "=");
			(*env)[i] = ft_strjoin(temp, item[2]);
			ft_strdel(&temp);
		}
		return ;
	}
	else
		append_var(env, item);
	return ;
}

void	rm_2d_arr_str(char ***old, char *item)
{
	char	**new;
	int		new_len;
	int		j;
	int		i;

	new_len = 0;
	i = 0;
	j = 0;
	new = NULL;
	if ((new_len = get_2darr_len(*old)) > 0)
		if (!(new = (char **)malloc((new_len) * sizeof(char *))))
			return ;
	if (get_env(*old, item) == -1)
		return ;
	while ((*old)[i])
	{
		if (!ft_strncmp((*old)[i], item, ft_strlen(item)))
			i++;
		else
			new[j++] = ft_strdup((*old)[i++]);
	}
	new[j] = NULL;
	mk_2d_arr_clean(old);
	*old = new;
	return ;
}
