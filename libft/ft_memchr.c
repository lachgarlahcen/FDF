/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 13:45:09 by atafah            #+#    #+#             */
/*   Updated: 2018/10/21 05:18:42 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		my_char;
	size_t				i;
	const unsigned char	*ptr;

	my_char = (unsigned char)c;
	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == my_char)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}
