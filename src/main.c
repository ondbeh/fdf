/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:47 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/22 11:47:35 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

void	ft_exit_cleanly(t_vars *vars, int i)
{
	free_int_map(vars->map->map);
	free(vars->map);
	mlx_terminate(vars->mlx);
	exit (i);
}

void	key_hook_control(void *par)
{
	t_vars	*vars;

	vars = (t_vars *) par;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		ft_exit_cleanly(vars, 0);
	else
		return ;
}

void	put_map_to_image(t_vars vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < WIN_L)
	{
		j = 0;
		while (j < WIN_W)
		{
			int red = (i * 255) / (WIN_L - 1);   // Red intensity increases horizontally
			int green = (j * 255) / (WIN_W - 1); // Green intensity increases vertically
			int blue = ((i + j) * 255) / (WIN_W + WIN_L - 2); // Combination of i and j for blue

			// Combine red, green, and blue into a single RGBA value using bitwise shifts
			int rgba = (red << 24) | (green << 16) | (blue << 8) | 0xFF; // Full opacity

			mlx_put_pixel(vars.img, j, i, rgba);
			//printf("%zu, %zu\n", i, j);
			//mlx_put_pixel(vars.img, vars.map->projection[i][j].x + 500, vars.map->projection[i][j].y + 400, 0XFFFF00);
			++j;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2 || !parse_map(&vars.map, argv[1]) || !project_map(vars.map))
		return (ft_putstr_fd("Error", 1), 1);
	vars.mlx = mlx_init(WIN_W, WIN_L, WIN_TITLE, false);
	if (!vars.mlx)
		printf("\n:(\n");
	vars.img = mlx_new_image(vars.mlx, WIN_W, WIN_L);
	if (!vars.img)
		printf("\n:(\n");
	put_map_to_image(vars);
	mlx_image_to_window(vars.mlx, vars.img, 0, 0);
	mlx_loop_hook(vars.mlx, &key_hook_control, &vars);
	mlx_loop(vars.mlx);
	free_int_map(vars.map->map);
	free(vars.map);
	return (0);
}
