/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:43 by csubires          #+#    #+#             */
/*   Updated: 2024/07/27 13:23:27 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	close_win(t_fdfs *fdfs)
{
	free_all(fdfs);
	exit (0);
	return (0);
}

static int	key_event(int keycode, t_fdfs *fdfs)
{
	if (keycode == KEY_ESC)
		close_win(fdfs);
	return (0);
}

static int	initialise_fdfs(t_fdfs *fdfs, t_map *map)
{
	fdfs->map = map;
	fdfs->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!fdfs->img)
		return (1);
	fdfs->mlx = mlx_init();
	fdfs->img->img = mlx_new_image(fdfs->mlx, WIN_W, WIN_H);
	fdfs->img->addr = mlx_get_data_addr(fdfs->img->img,
			&fdfs->img->bpp, &fdfs->img->sz_l, &fdfs->img->endian);
	fdfs->win = mlx_new_window(fdfs->mlx, WIN_W, WIN_H, "FDF 42 - CSUBIRES");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_fdfs	*fdfs;

	map = 0;
	parse_args(&map, argc, argv);
	fdfs = (t_fdfs *)ft_calloc(1, sizeof(t_fdfs));
	if (!fdfs || initialise_fdfs(fdfs, map))
	{
		free_all(fdfs);
		error_and_exit("main : initialise_fdfs or calloc");
	}
	mlx_hook(fdfs->win, 17, 17, close_win, fdfs);
	mlx_hook(fdfs->win, 2, 0, key_event, fdfs);
	render_map(fdfs);
	mlx_loop(fdfs->mlx);
	free_all(fdfs);
	return (0);
}
