/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:14:10 by llachgar          #+#    #+#             */
/*   Updated: 2018/12/01 18:17:33 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_type(int key, t_fdf *fdf)
{
	if (key == 124)
		fdf->mv_lr += 10;
	if (key == 123)
		fdf->mv_lr -= 10;
	if (key == 125)
		fdf->mv_ud += 10;
	if (key == 126)
		fdf->mv_ud -= 10;
	if (key == 69)
		fdf->zoom += 1;
	if (key == 78)
		fdf->zoom -= 1;
	if (key == 13)
		fdf->h += 2;
	if (key == 1)
		fdf->h -= 2;
	if (key == 34)
		fdf->rot = 0.523599;
	if (key == 88)
		fdf->rot += 0.02;
	if (key == 86)
		fdf->rot -= 0.02;
	if (key == 49)
		fdf = change_color(fdf);
}

int		keyhook(int key, t_fdf *fdf)
{
	key_type(key, fdf);
	if (key == 53)
		exit(0);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
	return (0);
}

void	paint1(t_fdf *fdf, long couleur, int i)
{
	fdf->erreur = fdf->dy / 2;
	i = -1;
	while (++i < fdf->dy)
	{
		fdf->y += fdf->yincr;
		fdf->erreur += fdf->dx;
		if (fdf->erreur > fdf->dy)
		{
			fdf->erreur -= fdf->dy;
			fdf->x += fdf->xincr;
		}
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y, couleur);
	}
}

void	paint2(t_fdf *fdf, long couleur, int i)
{
	fdf->erreur = fdf->dx / 2;
	i = -1;
	while (++i < fdf->dx)
	{
		fdf->x += fdf->xincr;
		fdf->erreur += fdf->dy;
		if (fdf->erreur > fdf->dx)
		{
			fdf->erreur -= fdf->dx;
			fdf->y += fdf->yincr;
		}
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y, couleur);
	}
}

t_fdf	*init_fdf(t_fdf *fdf)
{
	fdf->mv_lr = 500;
	fdf->mv_ud = 500;
	fdf->zoom = 20;
	fdf->h = 0;
	fdf->iso = 0;
	fdf->rot = 0.523599;
	return (fdf);
}
