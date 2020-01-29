/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:24:39 by zmadi             #+#    #+#             */
/*   Updated: 2019/07/03 15:20:56 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_new_line(char **s, char **line, int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		temp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = temp;
	}
	else if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			reader;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((reader = (read(fd, buf, BUFF_SIZE))) > 0)
	{
		buf[reader] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		temp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = temp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (reader < 0)
		return (-1);
	else if (reader == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd));
}
