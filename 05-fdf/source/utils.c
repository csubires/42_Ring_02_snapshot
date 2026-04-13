/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:43 by csubires          #+#    #+#             */
/*   Updated: 2024/07/19 12:32:34 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error_and_exit(const char *msg)
{
	ft_printf("Error. \"%s\"", msg);
	exit(-1);
}

void	free_all(t_fdfs *fdfs)
{
	mlx_destroy_image(fdfs->mlx, fdfs->img->img);
	mlx_destroy_window(fdfs->mlx, fdfs->win);
	free_map(fdfs->map);
	if (fdfs->img)
		free(fdfs->img);
	free(fdfs);
}

static void	isometric(t_fdfs *fdfs, int *x, int *y, int z)
{
	int	tmp_x;
	int	tmp_y;

	(void)fdfs;
	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(DEGREE_30);
	*y = -z + (tmp_x + tmp_y) * sin(DEGREE_30);
}

t_point	get_coordinate(t_fdfs *fdfs, t_point point)
{
	int	ini_pos;

	ini_pos = ft_maximum((WIN_W / fdfs->map->width / 2), \
	(WIN_H / fdfs->map->height / 2));
	point.x *= ini_pos;
	point.y *= ini_pos;
	point.z *= 1 + (ini_pos / fdfs->map->max_z);
	isometric(fdfs, &point.x, &point.y, point.z);
	point.x += WIN_W / 2;
	point.y += (WIN_H - fdfs->map->height * ini_pos) / 2;
	return (point);
}
