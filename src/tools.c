/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:44:51 by llachgar          #+#    #+#             */
/*   Updated: 2018/12/01 16:52:43 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		rot(int *x, int *y, double rot)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(rot) - previous_y * sin(rot);
	*y = previous_x * sin(rot) + previous_y * cos(rot);
}

unsigned long	creatergb(void)
{
	int r;
	int g;
	int b;

	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static void		iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void			make_iso(t_fdf *fdf)
{
	int		i;
	int		h;
	t_line	*temp;

	temp = fdf->line;
	while (fdf->line)
	{
		i = 0;
		while (fdf->line->points[i])
		{
			h = 0;
			if (fdf->line->points[i]->value != 0)
				h = fdf->line->points[i]->value + fdf->h;
			iso(&(fdf->line->points[i]->x), &(fdf->line->points[i]->y)
			, fdf->line->points[i]->value + h);
			i++;
		}
		fdf->line = fdf->line->next;
	}
	fdf->line = temp;
}

void			make_rot(t_fdf *fdf)
{
	int		i;
	t_line	*temp;

	temp = fdf->line;
	while (fdf->line)
	{
		i = 0;
		while (fdf->line->points[i])
		{
			rot(&(fdf->line->points[i]->x)
			, &(fdf->line->points[i]->y), fdf->rot);
			i++;
		}
		fdf->line = fdf->line->next;
	}
	fdf->line = temp;
}
