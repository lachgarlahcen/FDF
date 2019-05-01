/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 21:39:49 by atafah            #+#    #+#             */
/*   Updated: 2018/10/20 22:01:36 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int i;
	int z;

	if (!str)
		return (NULL);
	z = ft_strlen(str) - 1;
	i = 0;
	while (i <= z)
		ft_charswap(&str[i++], &str[z--]);
	return (str);
}
