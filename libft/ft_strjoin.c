/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:02:15 by atafah            #+#    #+#             */
/*   Updated: 2018/10/20 16:21:56 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fresh;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL || !(fresh = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			fresh[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			fresh[i] = s2[j];
			j++;
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
