/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:16:58 by zmadi             #+#    #+#             */
/*   Updated: 2019/06/06 08:28:02 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	find;
	char	*str;

	str = (char *)s;
	find = (char)c;
	i = ft_strlen(s);
	if (find == 0)
		return (str + i);
	while (0 <= i)
	{
		if (str[i] == find)
			return (str + i);
		i--;
	}
	return (NULL);
}
