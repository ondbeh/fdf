/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:24:01 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/19 09:29:18 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	fill_lines(t_map *map, char *line, size_t i)
{
	size_t	j;
	char	**split_line;
	char	*color_start;

	j = 0;
	split_line = ft_split(line, ' ');
	if (!split_line)
		error_handler(map, "Error:\nFailed to split line\n");
	while (split_line[j])
	{
		map->map[i][j] = ft_atoi(split_line[j]);
		color_start = ft_strchr(split_line[j], ',');
		if (color_start)
			map->color_map[i][j] = ft_atoi_base(color_start + 3, 16);
		else
			map->color_map[i][j] = BASE_COLOR;
		free (split_line[j]);
		++j;
	}
	free (split_line);
}

static void	fill_maps(t_map *map, char *path)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_handler(map, "Error:\nFailed to open file\n");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_lines(map, line, i);
		free (line);
		line = get_next_line(fd);
		++i;
	}
	close (fd);
}

void	get_map_sizes(t_map *map, char *path)
{
	int		fd;
	size_t	width;
	size_t	length;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Error:\nFailed to open file\n");
	width = 0;
	length = 0;
	line = get_next_line(fd);
	while (line)
	{
		++length;
		if (width == 0)
			width = ft_count_words(line, ' ');
		free (line);
		line = get_next_line(fd);
	}
	map->width = width;
	map->length = length;
	close (fd);
}

int	parse_map(t_map **map, char *path)
{
	*map = ft_calloc(1, sizeof(t_map));
	if (!*map)
		error_exit("Error:\nFailed to allocate memory\n");
	get_map_sizes(*map, path);
	allocate_maps(*map);
	fill_maps(*map, path);
	return (1);
}
