/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:38:56 by zmadi             #+#    #+#             */
/*   Updated: 2019/06/06 08:19:24 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	find;

	i = 0;
	find = (char)c;
	str = (char *)s;
	while (str[i] != '\0' && str[i] != find)
	{
		i++;
	}
	if (str[i] == find)
		return (str + i);
	return (NULL);
}
