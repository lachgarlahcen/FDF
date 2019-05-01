/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 06:19:17 by atafah            #+#    #+#             */
/*   Updated: 2018/10/12 14:01:03 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	my_char;
	char			*ptr;

	i = 0;
	my_char = (unsigned char)c;
	ptr = (char *)b;
	while (i < len)
	{
		ptr[i] = my_char;
		i++;
	}
	return (b);
}
