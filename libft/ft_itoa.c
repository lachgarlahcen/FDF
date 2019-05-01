/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 10:06:26 by atafah            #+#    #+#             */
/*   Updated: 2018/10/20 15:45:33 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse(char *str, int index)
{
	int		j;
	char	temp;

	j = ft_strlen(str) - 1;
	while (index <= j)
	{
		temp = str[index];
		str[index] = str[j];
		str[j] = temp;
		index++;
		j--;
	}
}

static void	ft_func(int *rptr, int *nptr, unsigned int *hptr, int *counterptr)
{
	*rptr = *nptr;
	if (*nptr < 0)
	{
		*hptr = -(*nptr);
		*counterptr = 1;
	}
	else
	{
		*hptr = *nptr;
		*counterptr = 0;
	}
	if (*nptr == 0)
		*counterptr = 1;
	while (*nptr != 0)
	{
		*nptr = *nptr / 10;
		(*counterptr)++;
	}
}

static void	ft_iptr(int *iptr)
{
	*iptr = 0;
}

static void	ft_third_func(char *ptr, int *iptr, int *rptr)
{
	ptr[*iptr] = '\0';
	if (*rptr < 0)
		ft_reverse(ptr, 1);
	else
		ft_reverse(ptr, 0);
}

char		*ft_itoa(int n)
{
	int				counter;
	unsigned int	h;
	int				i;
	int				r;
	char			*ptr;

	ft_iptr(&i);
	ft_func(&r, &n, &h, &counter);
	if ((ptr = (char *)malloc(sizeof(char) * (counter + 1))))
	{
		if (r < 0)
		{
			ptr[i] = '-';
			i++;
		}
		while (i < counter)
		{
			ptr[i] = ((h % 10) + '0');
			h = h / 10;
			i++;
		}
		ft_third_func(ptr, &i, &r);
		return (ptr);
	}
	return (NULL);
}
