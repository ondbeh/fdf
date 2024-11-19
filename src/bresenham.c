/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:56:21 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/19 07:37:22 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	project_isometric(t_vars *vars, t_coordinates *point)
{
	t_coordinates	rotated;

	rotated.x = -point->y;
	rotated.y = point->x;
	point->x = (rotated.y - rotated.x) * cos(M_PI / 6);
	point->y = (rotated.x + rotated.y + vars->map->width * 1.5) * sin(M_PI / 6) - point->z * vars->height_scale;
}

void	shift_and_scale(t_vars *vars, t_coordinates *point)
{
	point->x *= vars->size_len_scale * 0.8;
	point->y *= vars->size_len_scale * 0.8;
}

void	bresenham(t_vars *vars, t_coordinates point1, t_coordinates point2)
{
	double	dx;
	double	dy;
	double	max_step;

	project_isometric(vars, &point1);
	project_isometric(vars, &point2);
	shift_and_scale(vars, &point1);
	shift_and_scale(vars, &point2);
	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	max_step = fmax(fabs(dx), fabs(dy));
	dx /= max_step;
	dy /= max_step;
	while ((int)(point1.x - point2.x) || (int)(point1.y - point2.y))
	{
		if (point1.x >= 0 && point1.x < WIN_W && point1.y >= 0 && point1.y < WIN_L)
			mlx_put_pixel(vars->img, (int)point1.x, (int)point1.y, 0xFF00FF);
		point1.x += dx;
		point1.y += dy;
	}
}
