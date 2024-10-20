/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:47 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/20 10:44:11 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;
	size_t	i;
	size_t	j;


	if (argc != 2 || !parse_map(&map, argv[1]) || !project_map(map))
		return (ft_putstr_fd("Error", 1), 1);
	i = 0;
	ft_putnbr_fd(map->length, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(map->width, 1);
	ft_putchar_fd('\n', 1);

	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%d [%f, %f]", map->map[i][j], map->projection[i][j].x, map->projection[i][j].y);
			if (j < map->width - 1)
				ft_putchar_fd(' ', 1);
			++j;
		}
		ft_putchar_fd('\n', 1);
		++i;
	}
	free_int_map(map->map);
	free(map);
	return (0);
}
