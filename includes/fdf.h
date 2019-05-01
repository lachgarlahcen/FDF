/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:46:42 by llachgar          #+#    #+#             */
/*   Updated: 2018/12/01 22:02:03 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"

typedef struct	s_point
{
	long		color;
	int			x;
	int			y;
	int			value;
}				t_point;

typedef struct	s_line
{
	struct s_line	*next;
	t_point			**points;
}				t_line;

typedef struct	s_fdf
{
	int		mv_lr;
	int		h;
	int		mv_ud;
	int		zoom;
	double	rot;
	void	*mlx;
	void	*win;
	int		iso;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xincr;
	int		yincr;
	int		erreur;
	t_line	*temp;
	t_line	*line;

}				t_fdf;

unsigned long	creatergb();
t_fdf			*init_fdf(t_fdf *fdf);
void			make_iso(t_fdf *fdf);
void			make_rot(t_fdf *fdf);
long int		hex2int(char *hex);
void			init_win(t_fdf *fdf);
void			draw_line(t_fdf *fdf, t_point *point1
, t_point *point2, long couleur);
void			draw(t_fdf *fdf);
t_fdf			*change_color(t_fdf *fdf);
t_line			*make_point(t_line *line, int x);
int				keyhook(int key, t_fdf *fdf);
void			paint2(t_fdf *fdf, long couleur, int i);
void			paint1(t_fdf *fdf, long couleur, int i);

#endif
