/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 18:27:11 by atafah            #+#    #+#             */
/*   Updated: 2018/10/20 18:57:01 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *s))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	if (s != NULL)
	{
		while (i < (unsigned int)ft_strlen(s) && s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}
