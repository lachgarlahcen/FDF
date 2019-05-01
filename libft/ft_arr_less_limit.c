/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_less_limit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 03:39:00 by atafah            #+#    #+#             */
/*   Updated: 2018/10/21 03:41:16 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arr_less_limit(int *arr, int length, int limit)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (arr[i] > limit)
			return (0);
		i++;
	}
	return (1);
}
