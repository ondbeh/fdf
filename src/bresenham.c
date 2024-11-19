/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:56:21 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/19 13:25:53 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	project_isometric(t_vars *vars, t_node *point)
{
	t_node	rotated;

	rotated.x = -point->y;
	rotated.y = point->x;
	point->x = (rotated.y - rotated.x) * cos(M_PI / 6);
	point->y = (rotated.x + rotated.y + vars->map->width * 1.5)
		* sin(M_PI / 6) - point->z * vars->height_scale;
}

static void	project_and_scale(t_vars *vars, t_node *point1, t_node *point2)
{
	project_isometric(vars, point1);
	project_isometric(vars, point2);
	point1->x *= vars->size_len_scale;
	point1->y *= vars->size_len_scale;
	point2->x *= vars->size_len_scale;
	point2->y *= vars->size_len_scale;
}

static int	get_color(int color1, int color2, double ratio)
{
	int	red;
	int	green;
	int	blue;

	red = (int)((1 - ratio) * ((color1 >> 24) & 0xFF))
		+ (int)(ratio * ((color2 >> 24) & 0xFF));
	green = (int)((1 - ratio) * ((color1 >> 16) & 0xFF))
		+ (int)(ratio * ((color2 >> 16) & 0xFF));
	blue = (int)((1 - ratio) * ((color1 >> 8) & 0xFF))
		+ (int)(ratio * ((color2 >> 8) & 0xFF));
	return ((red << 24) | (green << 16) | (blue << 8) | FULLY_OPAQUE);
}

static int	is_visible(t_node point)
{
	return (point.x >= 0 && point.x < WIN_W && point.y >= 0 && point.y < WIN_L);
}

void	bresenham(t_vars *vars, t_node point1, t_node point2)
{
	double	dx;
	double	dy;
	double	max_step;
	double	gradient;
	int		color;

	project_and_scale(vars, &point1, &point2);
	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	max_step = fmax(fabs(dx), fabs(dy));
	dx /= max_step;
	dy /= max_step;
	gradient = 0;
	while (gradient <= max_step)
	{
		color = get_color(point1.color, point2.color, gradient / max_step);
		if (is_visible(point1))
			mlx_put_pixel(vars->img, (int)point1.x, (int)point1.y, color);
		point1.x += dx;
		point1.y += dy;
		++gradient;
	}
}
