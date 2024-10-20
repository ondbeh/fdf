/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 09:14:44 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/20 10:45:35 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_coordinates **free_projection(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->projection[i])
		free (map->projection[i]);
	free (map->projection);
	return ((t_coordinates **) free_int_map(map->map));
}

t_coordinates	*calculate_projection(t_map *map, size_t y)
{
	t_coordinates	*coordinates;
	size_t			x;

	x = 0;
	coordinates = ft_calloc(map->width + 1, sizeof(t_coordinates));
	while (x < map->width)
	{
		coordinates[x].y = (x - y) * cos(30 * M_PI / 180);
		coordinates[x].x = (x + y) * sin(30 * M_PI / 180) - map->map[y][x];
		++x;
	}
	return (coordinates);
}

int	project_map(t_map *map)
{
	size_t	i;

	i = 0;
	map->projection = ft_calloc(map->length + 1, sizeof(t_coordinates *));
	if (!map->projection)
		return ((int)free_int_map(map->map));
	while (i < map->length)
	{
		map->projection[i] = calculate_projection(map, i);
		if (!map->projection[i])
			return ((int)(map->projection = free_projection(map)));
		++i;
	}
	return (1);
}
