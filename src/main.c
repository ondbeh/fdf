/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:47 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/18 11:40:35 by obehavka         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2 || !parse_map(&vars.map, argv[1]))
		return (ft_putstr_fd("Error", 1), 1);
	vars.mlx = mlx_init(WIN_W, WIN_L, WIN_TITLE, false);
	if (!vars.mlx)
		printf("\n:(\n");
	vars.img = mlx_new_image(vars.mlx, WIN_W, WIN_L);
	if (!vars.img)
		printf("\n:(\n");
	put_map_to_image(&vars);
	mlx_image_to_window(vars.mlx, vars.img, 0, 0);
	mlx_loop_hook(vars.mlx, &key_hook_control, &vars);
	mlx_loop(vars.mlx);
	free_int_map(vars.map->map);
	free(vars.map);
	return (0);
}
