/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:35:04 by zmadi             #+#    #+#             */
/*   Updated: 2020/01/26 12:42:19 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int		get_2darr_len(char **arr2d)
{
	int i;

	if (!arr2d)
		return (-1);
	else
	{
		i = 0;
		while (arr2d[i])
			i++;
	}
	return (i);
}

char	**cpy_2darr(char **src)
{
	int		len;
	int		i;
	char	**dst_env;

	dst_env = NULL;
	i = 0;
	if ((len = get_2darr_len(src)) > 0)
	{
		if (!(dst_env = (char **)malloc((len + 1) * sizeof(char *))))
			return (dst_env);
		while (src[i] != NULL)
		{
			dst_env[i] = ft_strdup(src[i]);
			i++;
		}
		dst_env[i] = NULL;
	}
	return (dst_env);
}

void	mk_2d_arr_clean(char ***arr)
{
	int i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while ((*arr)[i])
	{
		ft_strdel(&(*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
	return ;
}

char	**gimme_2darr_space(int size)
{
	char **new;

	new = NULL;
	if (!(new = (char **)malloc(size * sizeof(char *))))
		return (NULL);
	return (new);
}
