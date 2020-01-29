/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:56:01 by zmadi             #+#    #+#             */
/*   Updated: 2019/06/14 16:15:32 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned int	i;
	unsigned char	ptr;

	dest = (unsigned char*)s1;
	src = (unsigned char*)s2;
	ptr = (unsigned char)c;
	i = 0;
	if (!s1 || !s2)
		return (s1);
	while (i < n)
	{
		dest[i] = src[i];
		if (dest[i] == ptr)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
