/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:10:45 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/20 09:00:08 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_map_sizes(t_map *map, char ***str_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str_map[i])
	{
		j = 0;
		while (str_map[i][j])
			j++;
		if (i == 0)
			map->width = j;
		else if (map->width != j)
			return (0);
		++i;
	}
	map->length = i;
	return (1);
}

char	***free_string_map(char ***map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			free (map[i][j++]);
		free (map[i++]);
	}
	free (map);
	return (NULL);
}

int	**free_int_map(int **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		free (map[i++]);
	free (map);
	return (NULL);
}
