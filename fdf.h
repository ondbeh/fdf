/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:59 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/25 14:31:08 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define BASE_COLOR 0xFFFFFFFF
# define FULLY_OPAQUE 0xFF
# define WIN_W 800
# define WIN_L 600
# define BIG_MAP 350
# define BIG_MAP_HOR_PUSH_SCALE 1.1
# define SMALL_MAP_HOR_PUSH_SCALE 1.5
# define SMALL_MAP_SIZE_SCALE 0.8
# define WIN_TITLE "FdF"

typedef struct s_node
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_node;

typedef struct s_map
{
	size_t		width;
	size_t		length;
	int			**map;
	int			**color_map;
}				t_map;

typedef struct s_vars
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	double		size_scale;
	double		horizontal_push_scale;
	double		height_scale;

}				t_vars;

void			**free_int_map(int **map);
void			parse_map(t_map **map, char *path);
void			bresenham(t_vars *vars, t_node point1, t_node point2);
void			put_map_to_image(t_vars *vars);
void			error_handler(t_map *map, char *message);
void			error_exit(char *message);
void			allocate_maps(t_map *map);

#endif
