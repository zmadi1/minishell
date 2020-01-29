/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:13:40 by zmadi             #+#    #+#             */
/*   Updated: 2019/06/14 16:16:23 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ptr;
	int				i;

	i = 0;
	str = (unsigned char*)s;
	ptr = (unsigned char)c;
	if (!s)
		return (NULL);
	while (n--)
	{
		if (str[i] == ptr)
			return (str + i);
		i++;
	}
	return (NULL);
}
