/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:43 by csubires          #+#    #+#             */
/*   Updated: 2024/07/19 12:35:51 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	close_win(t_fdfs *fdfs)
{
	free_all(fdfs);
	exit (0);
	return (0);
}

static int	initialise_fdfs(t_fdfs *fdfs, t_map *map)
{
	fdfs->map = map;
	fdfs->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!fdfs->img)
		return (1);
	fdfs->menu = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!fdfs->menu)
		return (1);
	reset_fdfs(fdfs);
	return (0);
}

static void	initialise_mlx(t_fdfs *fdfs)
{
	fdfs->mlx = mlx_init();
	fdfs->img->img = mlx_new_image(fdfs->mlx, WIN_W, WIN_H);
	fdfs->img->addr = mlx_get_data_addr(fdfs->img->img,
			&fdfs->img->bpp, &fdfs->img->sz_l, &fdfs->img->endian);
	fdfs->win = mlx_new_window(fdfs->mlx, WIN_W, WIN_H, "FDF 42 - CSUBIRES");
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_fdfs	*fdfs;

	map = 0;
	srand(time(0));
	parse_args(&map, argc, argv);
	fdfs = (t_fdfs *)ft_calloc(1, sizeof(t_fdfs));
	if (!fdfs || initialise_fdfs(fdfs, map))
	{
		free_all(fdfs);
		error_and_exit("initialise_mlx", "initialise_fdfs or ft_calloc");
	}
	initialise_mlx(fdfs);
	mlx_hook(fdfs->win, 17, 17, close_win, fdfs);
	mlx_hook(fdfs->win, 2, 0, key_event, fdfs);
	render_menu(fdfs, 400, 600);
	render_map(fdfs);
	mlx_loop(fdfs->mlx);
	free_all(fdfs);
	return (0);
}
