/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:58:13 by atafah            #+#    #+#             */
/*   Updated: 2018/10/28 14:27:46 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../libft/libft.h"

# define BUFF_SIZE 50

int	get_next_line(const int fd, char **line);
int nextof(int fd, char **line, char **s);

#endif
