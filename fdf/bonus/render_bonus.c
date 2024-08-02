/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:43 by csubires          #+#    #+#             */
/*   Updated: 2024/07/19 11:16:23 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	render_menu(t_fdfs *fdfs, int width, int height)
{
	int		x;
	int		y;

	fdfs->menu->img = mlx_new_image(fdfs->mlx, width, height);
	fdfs->menu->addr = mlx_get_data_addr(fdfs->menu->img, \
	&fdfs->menu->bpp, &fdfs->menu->sz_l, &fdfs->menu->endian);
	x = -1;
	while (x++ <= width)
	{
		y = -1;
		while (y++ <= height)
		{
			if (x < 5 || x > (width - 6) || y < 5 || y > (height - 6) || \
			y == 150 || y == 260 || y == 400 || y == 510)
				set_pixel(fdfs->menu, x, y, MENU_BORDER);
			else
				set_pixel(fdfs->menu, x, y, MENU_BG);
		}
	}
	return (1);
}

void	show_menu(t_fdfs *fdfs)
{
	int		y;
	int		x;

	x = (WIN_W - 400) / 2;
	y = (WIN_H - 600) / 2;
	mlx_put_image_to_window(fdfs->mlx, fdfs->win, fdfs->menu->img, x, y);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 40, 0xFFFFFF, M_TEXT_00);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 30, 0xFFFFFF, M_TEXT_01);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 30, 0xFFFFFF, M_TEXT_02);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 30, 0xFFFFFF, M_TEXT_03);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 50, 0xF7DC6F, M_TEXT_04);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 130, y += 30, 0xFFFFFF, M_TEXT_05);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 30, 0xFFFFFF, M_TEXT_06);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 50, 0xF7DC6F, M_TEXT_07);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 120, y += 30, 0xFFFFFF, M_TEXT_08);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 30, 0xFFFFFF, M_TEXT_09);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 220, y += 30, 0xFFFFFF, M_TEXT_10);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 50, 0xF7DC6F, M_TEXT_11);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 70, y += 30, 0xFFFFFF, M_TEXT_12);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 70, y += 30, 0xFFFFFF, M_TEXT_13);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 50, 0xFFFFFF, M_TEXT_14);
	mlx_string_put(fdfs->mlx, fdfs->win, x + 40, y += 30, 0xFFFFFF, M_TEXT_15);
}

static void	init_bresenham(t_point *start, t_point *end,
t_point *diff, t_point *sign)
{
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
	diff->x = ft_abs(end->x - start->x);
	diff->y = ft_abs(end->y - start->y);
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
		set_pixel(fdfs->img, cur.x, cur.y, get_color(start, end, cur, diff));
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
	if (fdfs->zoom)
	{
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
	}
	mlx_put_image_to_window(fdfs->mlx, fdfs->win, fdfs->img->img, 0, 0);
}
