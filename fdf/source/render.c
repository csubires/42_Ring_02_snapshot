/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:43 by csubires          #+#    #+#             */
/*   Updated: 2024/07/19 12:14:07 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	new_point(int x, int y, t_fdfs *fdfs)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = fdfs->map->z_gen[y][x];
	return (new);
}

static void	set_pixel(t_img *img, int x, int y, int color)
{
	int	pixel;

	if (y >= WIN_H || x >= WIN_W || y < 0 || x < 0)
		return ;
	pixel = (y * img->sz_l) + (x * (img->bpp / 8));
	if (img->endian == 1)
	{
		img->addr[pixel + 0] = (color >> 24);
		img->addr[pixel + 1] = (color >> 16) & 0xFF;
		img->addr[pixel + 2] = (color >> 8) & 0xFF;
		img->addr[pixel + 3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		img->addr[pixel + 0] = (color) & 0xFF;
		img->addr[pixel + 1] = (color >> 8) & 0xFF;
		img->addr[pixel + 2] = (color >> 16) & 0xFF;
		img->addr[pixel + 3] = (color >> 24);
	}
}

static void	init_bresenham(t_point *start, t_point *end,
	t_point *diff, t_point *sign)
{
	diff->x = ft_abs(end->x - start->x);
	diff->y = ft_abs(end->y - start->y);
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
}

static void	bresenham(t_fdfs *fdfs, t_point start, t_point end)
{
	t_point	cur;
	t_point	sign;
	t_point	diff;
	int		line;
	int		tmp;

	init_bresenham(&start, &end, &diff, &sign);
	line = diff.x - diff.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		set_pixel(fdfs->img, cur.x, cur.y, BG_COLOR);
		tmp = line * 2;
		if (tmp > -diff.y)
		{
			line -= diff.y;
			cur.x += sign.x;
		}
		if (tmp < diff.x)
		{
			line += diff.x;
			cur.y += sign.y;
		}
	}
}

void	render_map(t_fdfs *fdfs)
{
	int	x;
	int	y;

	ft_bzero(fdfs->img->addr, WIN_W * WIN_H * (fdfs->img->bpp / 8));
	y = -1;
	while (++y < fdfs->map->height)
	{
		x = -1;
		while (++x < fdfs->map->width)
		{
			if (x < fdfs->map->width - 1)
				bresenham(fdfs,
					get_coordinate(fdfs, new_point(x, y, fdfs)),
					get_coordinate(fdfs, new_point(x + 1, y, fdfs)));
			if (y < fdfs->map->height - 1)
				bresenham(fdfs,
					get_coordinate(fdfs, new_point(x, y, fdfs)),
					get_coordinate(fdfs, new_point(x, y + 1, fdfs)));
		}
	}
	mlx_put_image_to_window(fdfs->mlx, fdfs->win, fdfs->img->img, 0, 0);
}
