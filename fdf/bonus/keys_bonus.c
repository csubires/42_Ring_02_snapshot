/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:43 by csubires          #+#    #+#             */
/*   Updated: 2024/07/27 13:23:51 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	zoom_and_altitude(int keycode, t_fdfs *fdfs)
{
	if (keycode == KEY_Q && fdfs->zoom > 0)
		fdfs->zoom -= ZOOM_STEP;
	if (keycode == KEY_E && fdfs->zoom < 100)
		fdfs->zoom += ZOOM_STEP;
	if (keycode == KEY_G)
		if (fdfs->flat < 10)
			fdfs->flat += ALTITUDE_STEP;
	if (keycode == KEY_V)
		if (fdfs->flat > -10)
			fdfs->flat -= ALTITUDE_STEP;
}

static void	move(int keycode, t_fdfs *fdfs)
{
	if (keycode == KEY_DOWN)
		fdfs->step_y += STEP;
	if (keycode == KEY_UP)
		fdfs->step_y -= STEP;
	if (keycode == KEY_RIGHT)
		fdfs->step_x += STEP;
	if (keycode == KEY_LEFT)
		fdfs->step_x -= STEP;
}

static void	rotation(int keycode, t_fdfs *fdfs)
{
	if (keycode == KEY_S)
		fdfs->rotate_x += ROT_STEP;
	if (keycode == KEY_W)
		fdfs->rotate_x -= ROT_STEP;
	if (keycode == KEY_C)
		fdfs->rotate_y += ROT_STEP;
	if (keycode == KEY_F)
		fdfs->rotate_y -= ROT_STEP;
	if (keycode == KEY_A)
		fdfs->rotate_z += ROT_STEP;
	if (keycode == KEY_D)
		fdfs->rotate_z -= ROT_STEP;
}

static void	state(int keycode, t_fdfs *fdfs)
{
	if (keycode == KEY_J)
	{
		fdfs->state.map_color = 0;
		fdfs->state.rnd_color = !fdfs->state.rnd_color;
		set_palette(&fdfs->state.palette, 0);
	}
	if (keycode == KEY_M)
	{
		fdfs->state.rnd_color = 0;
		fdfs->state.map_color = !fdfs->state.map_color;
		set_palette(&fdfs->state.palette, 2);
	}
	if (keycode == KEY_R)
	{
		fdfs->state.map_color = 0;
		fdfs->state.rnd_color = 0;
		reset_fdfs(fdfs);
	}
	if (keycode == KEY_ENTER)
		fdfs->state.menu = !fdfs->state.menu;
}

int	key_event(int keycode, t_fdfs *fdfs)
{
	if (keycode != KEY_ENTER)
		fdfs->state.menu = 0;
	if (keycode == KEY_ESC)
		close_win(fdfs);
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move(keycode, fdfs);
	if (keycode == KEY_E || keycode == KEY_Q)
		zoom_and_altitude(keycode, fdfs);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D || keycode == KEY_C || keycode == KEY_F)
		rotation(keycode, fdfs);
	if (keycode == KEY_J || keycode == KEY_M || keycode == KEY_R
		|| keycode == KEY_ENTER)
		state(keycode, fdfs);
	if (keycode == KEY_V || keycode == KEY_G)
		zoom_and_altitude(keycode, fdfs);
	if (keycode == KEY_T)
		fdfs->state.zenith = !fdfs->state.zenith;
	render_map(fdfs);
	if (fdfs->state.menu)
		show_menu(fdfs);
	return (0);
}
