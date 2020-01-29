/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:50:56 by zmadi             #+#    #+#             */
/*   Updated: 2019/06/06 11:17:27 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t len1;
	size_t len2;

	if (*needle == '\0')
		return ((char*)haystack);
	len1 = ft_strlen(haystack);
	len2 = ft_strlen(needle);
	if (len1 < len)
		len = len1;
	while (*haystack != '\0' && len2 <= len)
	{
		if (ft_memcmp(haystack, needle, len2) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
