/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:00:34 by atafah            #+#    #+#             */
/*   Updated: 2018/11/18 03:50:04 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	my_char;
	char	*ptr;

	i = ft_strlen(s);
	j = 0;
	my_char = (char)c;
	while (j <= i)
	{
		if (my_char == s[j])
		{
			ptr = (char *)(s + j);
			return (ptr);
		}
		j++;
	}
	return (NULL);
}
