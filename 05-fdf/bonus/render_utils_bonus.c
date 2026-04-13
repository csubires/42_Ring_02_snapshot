/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:56:20 by csubires          #+#    #+#             */
/*   Updated: 2024/07/19 12:33:47 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	error_and_exit(const char *func, const char *msg)
{
	ft_printf("Error in function \"%s\": %s", func, msg);
	exit(-1);
}

void	rotate_x(t_fdfs *fdfs, int *y, int *z)
{
	float	tmp_y;

	tmp_y = *y;
	*y = (tmp_y * cos(fdfs->rotate_x)) + (*z * sin(fdfs->rotate_x));
	*z = (-tmp_y * sin(fdfs->rotate_x)) + (*z * cos(fdfs->rotate_x));
}

void	rotate_y(t_fdfs *fdfs, int *x, int *z)
{
	float	tmp_x;

	tmp_x = *x;
	*x = (*x * cos(fdfs->rotate_y)) + (*z * sin(fdfs->rotate_y));
	*z = (-tmp_x * sin(fdfs->rotate_y)) + (*z * cos(fdfs->rotate_y));
}

void	rotate_z(t_fdfs *fdfs, int *x, int *y)
{
	float	tmp_x;

	tmp_x = *x;
	*x = (*x * cos(fdfs->rotate_z)) - (*y * sin(fdfs->rotate_z));
	*y = (tmp_x * sin(fdfs->rotate_z)) + (*y * cos(fdfs->rotate_z));
}

void	set_pixel(t_img *img, int x, int y, int color)
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
