/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:46:50 by zmadi             #+#    #+#             */
/*   Updated: 2019/06/21 15:42:10 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*dst;
	unsigned char	src;
	size_t			i;

	i = 0;
	dst = (char*)b;
	src = (unsigned char)c;
	if (b || c)
	{
		while (i < len)
		{
			dst[i] = src;
			i++;
		}
		return (dst);
	}
	return (NULL);
}
