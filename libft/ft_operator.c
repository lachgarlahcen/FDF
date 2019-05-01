/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 03:53:17 by atafah            #+#    #+#             */
/*   Updated: 2018/10/21 03:56:39 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_operator(int a, int b, char operand)
{
	if (operand == '+')
		return (a + b);
	else if (operand == '-')
		return (a - b);
	else if (operand == 'x')
		return (a * b);
	else if (operand == '/')
		return (a / b);
	return (0);
}
