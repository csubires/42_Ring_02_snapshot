/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:43 by csubires          #+#    #+#             */
/*   Updated: 2024/07/18 11:59:28 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_all(t_fdfs *fdfs)
{
	mlx_destroy_image(fdfs->mlx, fdfs->img->img);
	mlx_destroy_image(fdfs->mlx, fdfs->menu->img);
	mlx_destroy_window(fdfs->mlx, fdfs->win);
	free_map(fdfs->map);
	if (fdfs->img)
		free(fdfs->img);
	if (fdfs->menu)
		free(fdfs->menu);
	free(fdfs);
}

void	isometric(t_fdfs *fdfs, int *x, int *y, int z)
{
	int	tmp_x;
	int	tmp_y;

	if (!fdfs->state.zenith)
		return ;
	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(DEGREE_30);
	*y = -z + (tmp_x + tmp_y) * sin(DEGREE_30);
}

t_point	new_point(int x, int y, t_fdfs *fdfs)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = fdfs->map->z_gen[y][x];
	if (fdfs->map->has_color)
		new.color = fdfs->map->color_file[y][x];
	else
		new.color = generate_color(fdfs, new.z);
	return (new);
}

t_point	get_coordinate(t_fdfs *fdfs, t_point point)
{
	point.x *= fdfs->zoom;
	point.y *= fdfs->zoom;
	point.z *= (fdfs->zoom / 10) * fdfs->flat;
	rotate_x(fdfs, &point.y, &point.z);
	rotate_y(fdfs, &point.x, &point.z);
	rotate_z(fdfs, &point.x, &point.y);
	isometric(fdfs, &point.x, &point.y, point.z);
	point.x += fdfs->step_x;
	point.y += fdfs->step_y;
	return (point);
}

void	reset_fdfs(t_fdfs *fdfs)
{
	fdfs->zoom = ft_maximum((WIN_W / fdfs->map->width / 2), \
	(WIN_H / fdfs->map->height / 2));
	fdfs->step_x = WIN_W / 2;
	fdfs->step_y = (WIN_H - fdfs->map->height * fdfs->zoom) / 2;
	fdfs->flat = 1 + (fdfs->zoom / fdfs->map->max_z);
	fdfs->rotate_x = 0;
	fdfs->rotate_y = 0;
	fdfs->rotate_z = 0;
	fdfs->state.menu = 0;
	fdfs->state.zenith = 1;
	fdfs->state.rnd_color = 0;
	fdfs->state.map_color = 0;
}
