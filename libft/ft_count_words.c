/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 00:39:30 by atafah            #+#    #+#             */
/*   Updated: 2018/10/21 00:47:43 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	len;
	int	words;

	i = 0;
	len = (int)ft_strlen(s);
	words = 0;
	if (s[0] != c && s[0] != '\0')
	{
		words++;
		i++;
	}
	while (i < len - 1)
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}
