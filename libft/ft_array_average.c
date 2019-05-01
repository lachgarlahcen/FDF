/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_average.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 03:24:12 by atafah            #+#    #+#             */
/*   Updated: 2018/10/21 03:29:26 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_average(int *arr, int length)
{
	int i;
	int average;

	i = 1;
	average = arr[0];
	while (i < length)
	{
		average += arr[i];
		i++;
	}
	average /= length;
	return (average);
}
