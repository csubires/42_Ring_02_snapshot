/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:43 by csubires          #+#    #+#             */
/*   Updated: 2024/07/19 12:40:48 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_map(t_map *map)
{
	int	x;

	if (!map)
		return ;
	if (map->z_gen)
	{
		x = -1;
		while (++x < map->height)
			if (map->z_gen[x])
				free(map->z_gen[x]);
		free(map->z_gen);
	}
	if (map->color_file)
	{
		x = -1;
		while (++x < map->height)
			if (map->color_file[x])
				free(map->color_file[x]);
		free(map->color_file);
	}
	free(map);
}

void	set_z_limits(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->z_gen[y][x] < map->min_z)
				map->min_z = map->z_gen[y][x];
			else if (map->z_gen[y][x] > map->max_z)
				map->max_z = map->z_gen[y][x];
		}
	}
}

void	create_struct_mem(t_map *map)
{
	int	x;

	map->z_gen = (int **)malloc(sizeof(int *) * map->height);
	map->color_file = (int **)malloc(sizeof(int *) * map->height);
	if (!map->z_gen || !map->color_file)
	{
		free_map(map);
		error_and_exit("create_struct_mem", "malloc Pt1");
	}
	x = -1;
	while (++x < map->height)
	{
		map->z_gen[x] = (int *)malloc(sizeof(int) * map->width);
		map->color_file[x] = (int *)malloc(sizeof(int) * map->width);
		if (!map->z_gen[x] || !map->color_file[x])
		{
			free_map(map);
			error_and_exit("create_struct_mem", "malloc Pt2");
		}
	}
}

static int	get_width(t_map *map, char *line)
{
	int		width;
	char	**split;

	if (!line)
		return (0);
	split = ft_split(line, ' ');
	if (!split)
	{
		free_map(map);
		error_and_exit("get_width", "split = ft_split");
	}
	width = 0;
	while (split[width])
		width++;
	ft_free_split(split);
	return (width);
}

t_map	*initialise_map(char *file)
{
	int		fd;
	t_map	*map;
	char	*line;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		error_and_exit(file, "Error to open file");
	}
	line = ft_get_next_line(fd);
	map->width = get_width(map, line);
	while (line)
	{
		map->height++;
		free(line);
		line = ft_get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
