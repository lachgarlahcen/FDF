/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:12:27 by atafah            #+#    #+#             */
/*   Updated: 2018/10/13 17:19:32 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if ((ptr = (char *)malloc(sizeof(char) * (size + 1))))
	{
		ft_memset(ptr, '\0', size + 1);
		return (ptr);
	}
	else
		return (NULL);
}
