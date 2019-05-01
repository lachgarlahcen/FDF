/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:59:55 by atafah            #+#    #+#             */
/*   Updated: 2018/11/16 20:16:09 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nextof(int fd, char **line, char **s)
{
	int index;

	index = 0;
	while (s[fd][index] != '\0' && s[fd][index] != '\n')
		index++;
	if (s[fd][index] == '\n')
	{
		*line = ft_strsub(s[fd], 0, index);
		s[fd] = ft_strdup(s[fd] + index + 1);
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][index] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	static char	*s[4096];

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > 4096)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		buffer[ret] = '\0';
		s[fd] = ft_strjoin(s[fd], buffer);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (nextof(fd, line, s));
}
