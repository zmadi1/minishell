/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 10:14:37 by zmadi             #+#    #+#             */
/*   Updated: 2019/06/21 11:35:48 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *charsrc;
	char *chardst;

	if (dst == NULL && src == NULL)
		return (NULL);
	charsrc = (char*)src;
	chardst = (char*)dst;
	if (src < dst)
		ft_memcpy(dst, src, len);
	if (src > dst)
	{
		while (len > 0)
		{
			chardst[len - 1] = charsrc[len - 1];
			len--;
		}
	}
	return (dst);
}
