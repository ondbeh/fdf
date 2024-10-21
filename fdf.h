/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:59 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/21 11:59:42 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>

# define WIN_W 1920
# define WIN_L 1080
# define WIN_TITLE "FdF"

typedef struct s_vars
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_vars;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_coordinates
{
	float			x;
	float			y;
}	t_coordinates;

typedef struct s_map
{
	size_t			width;
	size_t			length;
	int				**map;
	t_coordinates	**projection;
}	t_map;

char	***free_string_map(char ***map);
int		**free_int_map(int **map);
int		parse_map(t_map **map, char *path);
int		get_map_sizes(t_map *map, char ***str_map);
int		project_map(t_map *map);


#endif
