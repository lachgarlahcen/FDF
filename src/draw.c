/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:20:05 by llachgar          #+#    #+#             */
/*   Updated: 2018/12/01 22:33:26 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		init_win(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 5, creatergb(), "ZOOM:   -   +");
	mlx_string_put(fdf->mlx, fdf->win, 20, 20, creatergb(), "ROTATE: 4   6");
	mlx_string_put(fdf->mlx, fdf->win, 850, 5, creatergb(), "MOVE:  <  ^  >");
	mlx_string_put(fdf->mlx, fdf->win, 850, 20, creatergb(), "HIGHT: W     S");
	mlx_string_put(fdf->mlx, fdf->win, 400, 5, creatergb()
	, "CHANGE COLOR: space");
}

long int	hex2int(char *hex)
{
	long int	val;
	char		byte;

	val = 0;
	while (*hex)
	{
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}

void		draw_line(t_fdf *fdf, t_point *point1
, t_point *point2, long couleur)
{
	int i;

	i = 0;
	fdf->dx = abs((point2->x + fdf->mv_lr) - (point1->x + fdf->mv_lr));
	fdf->dy = abs((point2->y + fdf->mv_ud) - (point1->y + fdf->mv_ud));
	if ((point1->x + fdf->mv_lr) < (point2->x + fdf->mv_lr))
		fdf->xincr = 1;
	else
		fdf->xincr = -1;
	if ((point1->y + fdf->mv_ud) < (point2->y + fdf->mv_ud))
		fdf->yincr = 1;
	else
		fdf->yincr = -1;
	fdf->x = point1->x + fdf->mv_lr;
	fdf->y = point1->y + fdf->mv_ud;
	if (fdf->dx > fdf->dy)
		paint2(fdf, couleur, i);
	else
		paint1(fdf, couleur, i);
	mlx_pixel_put(fdf->mlx, fdf->win, point1->x + fdf->mv_lr
	, point1->y + fdf->mv_ud, couleur);
	mlx_pixel_put(fdf->mlx, fdf->win, point2->x + fdf->mv_lr
	, point2->y + fdf->mv_ud, couleur);
}

void		draw(t_fdf *fdf)
{
	int		i;
	t_line	*line;

	fdf->line = make_point(fdf->line, fdf->zoom);
	init_win(fdf);
	if (fdf->rot != 0.523599)
		make_rot(fdf);
	make_iso(fdf);
	line = fdf->line;
	while (fdf->line)
	{
		i = -1;
		while (fdf->line->points[++i])
		{
			if (fdf->line->points[i + 1])
				draw_line(fdf, fdf->line->points[i], fdf->line->points[i + 1]
				, fdf->line->points[i + 1]->color);
			if (fdf->line->next)
				draw_line(fdf, fdf->line->points[i], fdf->line->next->points[i]
				, fdf->line->next->points[i]->color);
		}
		fdf->line = fdf->line->next;
	}
	fdf->line = line;
}

t_fdf		*change_color(t_fdf *fdf)
{
	int		i;
	long	color;
	t_line	*temp;

	temp = fdf->line;
	color = creatergb();
	while (fdf->line)
	{
		i = 0;
		while (fdf->line->points[i])
		{
			fdf->line->points[i]->color = color;
			i++;
		}
		fdf->line = fdf->line->next;
	}
	fdf->line = temp;
	return (fdf);
}
