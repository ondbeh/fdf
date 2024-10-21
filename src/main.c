/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:47 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/21 13:05:23 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*img;


	if (argc != 2 || !parse_map(&map, argv[1]) || !project_map(map))
		return (ft_putstr_fd("Error", 1), 1);
	mlx = mlx_init(WIN_W, WIN_L, WIN_TITLE, false);
	if (!mlx)
		printf("\n:(\n");
	img = mlx_new_image(mlx, WIN_L, WIN_W);
	mlx_put_pixel(img, 960, 540, 0);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	free_int_map(map->map);
	free(map);
	return (0);
}
