/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:59 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/19 09:25:17 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define BASE_COLOR 0xFFFFFF
# define WIN_W 2880
# define WIN_L 1620
# define HEIHGT_SCALE 0.09
# define WIN_TITLE "FdF"

typedef struct s_coordinates
{
	double			x;
	double			y;
	double			z;
}	t_coordinates;

typedef struct s_map
{
	size_t			width;
	size_t			length;
	int				**map;
	int				**color_map;
}	t_map;

typedef struct s_vars
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	double		size_len_scale;
	double		size_wid_scale;
	double		height_scale;

}	t_vars;

int		**free_int_map(int **map);
int		parse_map(t_map **map, char *path);
void	get_map_sizes(t_map *map, char *path);
void	bresenham(t_vars *vars, t_coordinates point1, t_coordinates point2);
void	put_map_to_image(t_vars *vars);
void	error_handler(t_map *map, char *message);
void	error_exit(char *message);
void	allocate_maps(t_map *map);

#endif
