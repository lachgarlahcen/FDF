/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 11:09:29 by atafah            #+#    #+#             */
/*   Updated: 2018/10/13 11:15:37 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int h;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		h = -n;
	}
	else
		h = n;
	if (h > 9)
		ft_putnbr_fd(h / 10, fd);
	ft_putchar_fd(h % 10 + '0', fd);
}
