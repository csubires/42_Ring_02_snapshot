/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:57:52 by csubires          #+#    #+#             */
/*   Updated: 2024/07/18 09:25:58 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	random_color(void)
{
	return (((rand() % 250) << 16) | ((rand() % 250) << 8) | (rand() % 250));
}

static void	set_palete_default(t_palette *palette)
{
	palette->color_1 = COLOR_DF_1;
	palette->color_2 = COLOR_DF_2;
	palette->color_3 = COLOR_DF_3;
	palette->color_4 = COLOR_DF_4;
	palette->color_5 = COLOR_DF_5;
	palette->color_6 = COLOR_DF_6;
	palette->color_7 = COLOR_DF_7;
	palette->color_8 = COLOR_DF_8;
}

static void	set_palette_map(t_palette *palette)
{
	palette->color_1 = COLOR_MP_1;
	palette->color_2 = COLOR_MP_2;
	palette->color_3 = COLOR_MP_3;
	palette->color_4 = COLOR_MP_4;
	palette->color_5 = COLOR_MP_5;
	palette->color_6 = COLOR_MP_6;
	palette->color_7 = COLOR_MP_7;
	palette->color_8 = COLOR_MP_8;
}

static void	set_palette_rdm(t_palette *palette)
{
	palette->color_1 = random_color();
	palette->color_2 = random_color();
	palette->color_3 = random_color();
	palette->color_4 = random_color();
	palette->color_5 = random_color();
	palette->color_6 = random_color();
	palette->color_7 = random_color();
	palette->color_8 = random_color();
}

void	set_palette(t_palette *palette, int selected)
{
	if (selected == 0)
		set_palette_rdm(palette);
	if (selected == 1)
		set_palete_default(palette);
	if (selected == 2)
		set_palette_map(palette);
}
