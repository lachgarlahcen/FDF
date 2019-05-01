/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:21:55 by llachgar          #+#    #+#             */
/*   Updated: 2018/11/28 15:46:15 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*make(char *str)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	point->value = ft_atoi(str);
	if (ft_strchr(str, ','))
		point->color = hex2int(ft_strsplit(str, ',')[1]);
	else
		point->color = 0xffffff;
	return (point);
}

t_line	*make_line(char **vals, int i)
{
	t_line *line;

	line = (t_line *)malloc(sizeof(t_line));
	line->points = (t_point **)malloc(sizeof(t_point) * i);
	i = 0;
	while (vals[i])
	{
		line->points[i] = make(vals[i]);
		i++;
	}
	line->next = NULL;
	return (line);
}

t_line	*make_point(t_line *line, int x)
{
	int		i;
	int		y;
	t_line	*temp;

	temp = line;
	y = x;
	while (line)
	{
		i = -1;
		while (line->points[++i])
			if (i == 0)
			{
				line->points[i]->x = x;
				line->points[i]->y = y;
			}
			else
			{
				line->points[i]->x = line->points[i - 1]->x + x;
				line->points[i]->y = line->points[i - 1]->y;
			}
		y += x;
		line = line->next;
	}
	return (temp);
}

t_line	*read_file(int fd, t_line *line)
{
	t_line	*temp;
	char	**vals;
	char	*buff;
	int		i;
	int		j;

	j = 0;
	while (get_next_line(fd, &buff))
	{
		i = 0;
		vals = ft_strsplit(buff, ' ');
		while (vals[i])
			i++;
		if (j++ == 0)
		{
			line = make_line(vals, i);
			temp = line;
			continue ;
		}
		line->next = make_line(vals, i);
		line = line->next;
		j++;
	}
	return (temp);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		i;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf = init_fdf(fdf);
	if (argc == 2)
	{
		i = open(argv[1], O_RDONLY);
		if (i < 0)
		{
			ft_putendl("error");
			exit(0);
		}
		fdf->line = read_file(i, fdf->temp);
		close(i);
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, "lahcen lachgar");
		draw(fdf);
		mlx_key_hook(fdf->win, keyhook, fdf);
		mlx_loop(fdf->mlx);
	}
	ft_putendl("error");
	return (0);
}
