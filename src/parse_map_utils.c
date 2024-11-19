/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:10:45 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/19 09:19:14 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	**free_int_map(int **map)
{
	size_t	i;

	i = 0;
	while (map && map[i])
		free (map[i++]);
	free (map);
	return (NULL);
}

void	allocate_maps(t_map *map)
{
	size_t	i;

	i = 0;
	map->map = ft_calloc((map->length + 1), sizeof(int *));
	map->color_map = ft_calloc((map->length + 1), sizeof(int *));
	if (!map->map || !map->color_map)
		error_handler(map, "Error\nFailed to allocate memory");
	while (i < map->length)
	{
		map->map[i] = ft_calloc((map->width + 1), sizeof(int));
		map->color_map[i] = ft_calloc((map->width + 1), sizeof(int));
		if (!map->map[i] || !map->color_map[i])
			error_handler(map, "Error\nFailed to allocate memory");
		++i;
	}
}
