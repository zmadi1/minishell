/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 06:28:21 by zmadi             #+#    #+#             */
/*   Updated: 2019/06/06 14:11:54 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;
	int		i;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	s2 = (char*)malloc(sizeof(*s2) * (len + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
