/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:47 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 16:24:24 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	size_t	i;
	size_t	j;


	if (argc != 2 || !parse_map(&map, argv[1]))
		return (ft_putstr_fd("Error", 1), -1);
	i = 0;
	ft_putnbr_fd(map->length, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(map->width, 1);
	ft_putchar_fd('\n', 1);

	while (i < map->length )
	{
		j = 0;
		while (j < map->width)
		{
			ft_putnbr_fd(map->map[i][j], 1);
			if (j < map->width - 1)
				ft_putchar_fd(' ', 1);
			++j;
		}
		ft_putchar_fd('\n', 1);
		++i;
	}
	ft_putstr_fd("here\n", 1);
	free_int_map(map->map);
	free(map);
	return (0);
}
