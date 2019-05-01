/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:29:50 by atafah            #+#    #+#             */
/*   Updated: 2018/10/20 19:24:14 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		z;
	int		h;
	char	*tri;

	i = 0;
	h = 0;
	if (!s)
		return (NULL);
	z = ft_strlen(s) - 1;
	while (s[z] == ' ' || s[z] == '\n' || s[z] == '\t')
		z--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (z <= i)
		return (ft_strdup(""));
	if (!(tri = (char *)malloc(sizeof(char) * (z - i + 2))))
		return (NULL);
	while (i < z + 1)
		tri[h++] = s[i++];
	tri[h] = '\0';
	return (tri);
}
