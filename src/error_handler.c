/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:34:06 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/19 15:09:27 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	error_exit(char *message)
{
	write(2, message, ft_strlen(message));
	exit(1);
}

void	error_handler(t_map *map, char *message)
{
	free_int_map(map->map);
	free_int_map(map->color_map);
	free(map);
	error_exit(message);
}
