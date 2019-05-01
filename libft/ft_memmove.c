/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:48:31 by atafah            #+#    #+#             */
/*   Updated: 2018/10/21 05:16:58 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;
	int		length;

	i = 0;
	length = (int)len;
	d = (char *)dst;
	s = (char *)src;
	if (s < d)
	{
		while (length > 0)
		{
			d[length - 1] = s[length - 1];
			length--;
		}
	}
	else
		while (i < length)
		{
			d[i] = s[i];
			i++;
		}
	return ((void *)d);
}
