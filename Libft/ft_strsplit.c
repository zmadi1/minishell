/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:03:18 by zmadi             #+#    #+#             */
/*   Updated: 2020/01/26 13:03:27 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0' && s[i] != c)
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**splt;
	int		wrd;
	int		i;
	int		h;

	i = 0;
	wrd = 0;
	if (!(splt = (char **)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1)))
			|| (!s || !c))
		return (NULL);
	if (ft_wordcount(s, c) == 0)
		splt[0] = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		h = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (h < i)
			splt[wrd++] = ft_strsub(s, h, i - h);
	}
	splt[wrd] = (NULL);
	return (splt);
}
