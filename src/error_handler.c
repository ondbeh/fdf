/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:34:06 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/25 14:30:00 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	error_exit(char *message)
{
	ssize_t	bytes_written;

	bytes_written = write(2, message, ft_strlen(message));
	(void)bytes_written;
	exit(1);
}

void	error_handler(t_map *map, char *message)
{
	free_int_map(map->map);
	free_int_map(map->color_map);
	free(map);
	error_exit(message);
}
