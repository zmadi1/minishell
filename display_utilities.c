/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:36:50 by zmadi             #+#    #+#             */
/*   Updated: 2020/01/26 12:43:02 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	disp(char *str)
{
	if (str)
		ft_putendl(str);
}

void	ft_strarrayiter(char **arr, void (*dsp)(char *str))
{
	int i;

	i = 0;
	if (arr[i])
	{
		while (arr[i])
		{
			dsp(arr[i]);
			i++;
		}
	}
	return ;
}

int		ft_indexof(char *str, char c)
{
	if (str && c && (ft_strchr(str, c)))
		return (ft_strchr(str, c) - &str[0]);
	return (-1);
}
