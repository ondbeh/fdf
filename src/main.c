/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:47 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/19 15:23:52 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

static void	exit_cleanly(t_vars *vars)
{
	free_int_map(vars->map->map);
	free_int_map(vars->map->color_map);
	free(vars->map);
	mlx_terminate(vars->mlx);
	exit (0);
}

static void	key_hook_control(void *par)
{
	t_vars	*vars;

	vars = (t_vars *) par;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		exit_cleanly(vars);
	else
		return ;
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2)
		error_exit("Error:\nInvalid number of arguments\n");
	parse_map(&vars.map, argv[1]);
	vars.mlx = mlx_init(WIN_W, WIN_L, WIN_TITLE, false);
	if (!vars.mlx)
		error_handler(vars.map, "Error:\nFailed to initialize mlx\n");
	vars.img = mlx_new_image(vars.mlx, WIN_W, WIN_L);
	if (!vars.img)
	{
		mlx_terminate(vars.mlx);
		error_handler(vars.map, "Error:\nFailed to create image\n");
	}
	put_map_to_image(&vars);
	mlx_image_to_window(vars.mlx, vars.img, 0, 0);
	mlx_loop_hook(vars.mlx, &key_hook_control, &vars);
	mlx_loop(vars.mlx);
	exit_cleanly(&vars);
}
