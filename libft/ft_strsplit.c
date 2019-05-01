/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 01:56:22 by atafah            #+#    #+#             */
/*   Updated: 2018/10/21 00:47:33 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		words;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	if (*s == '\0')
	{
		tab[0] = (void *)0;
		i++;
	}
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		tab[i++] = ft_strsub(s, 0, ft_wordlen(s, c));
		while (*s && *s != c)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
