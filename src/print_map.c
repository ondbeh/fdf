/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:38:41 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/19 07:39:30 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

static double	get_jumps(t_map *map, size_t i, size_t j, size_t *jump_count)
{
	size_t	jump;
	size_t	jump_sum;

	jump = 0;
	jump_sum = 0;
	if (i < map->length - 1)
	{
		jump = abs(map->map[i][j] - map->map[i + 1][j]);
		jump_sum += jump;
		if (jump)
			++(*jump_count);
	}
	if (j < map->width - 1)
	{
		jump = abs(map->map[i][j] - map->map[i][j + 1]);
		jump_sum += jump;
		if (jump)
			++(*jump_count);
	}
	return (jump_sum);
}

static double	get_jump_average(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	jump_count;
	size_t	total_jumps;

	i = 0;
	total_jumps = 0;
	jump_count = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			total_jumps += get_jumps(map, i, j, &jump_count);
			++j;
		}
		++i;
	}
	if (jump_count == 0)
		return (1);
	return ((double) total_jumps / jump_count);
}

static void	get_size_scale(t_vars *vars)
{
	size_t	total_size;
	double	len_scale;
	double	wid_scale;

	total_size = (vars->map->width + vars->map->length);
	len_scale = ((double)WIN_L / (double)(total_size - 1));
	printf("len_scale = %f\n", len_scale);
	wid_scale = ((double)WIN_W /(double) (total_size - 1));
	printf("wid_scale = %f\n", wid_scale);
	vars->size_len_scale = fmax(len_scale, wid_scale);
	vars->size_wid_scale = fmax(len_scale, wid_scale);
}

void	put_map_to_image(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	vars->height_scale = 0.9 / get_jump_average(vars->map);
	get_size_scale(vars);
	printf("height_scale = %f\n", vars->height_scale);
	while (i < vars->map->length)
	{
		j = 0;
		while (j < vars->map->width)
		{
			if (i < vars->map->length - 1)
				bresenham(vars, (t_coordinates){i, j, vars->map->map[i][j]}, (t_coordinates){i + 1, j, vars->map->map[i + 1][j]});
			if (j < vars->map->width - 1)
				bresenham(vars, (t_coordinates){i, j, vars->map->map[i][j]}, (t_coordinates){i, j + 1, vars->map->map[i][j + 1]});
			++j;
		}
		++i;
	}
}
