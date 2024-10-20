/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:59 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 16:24:11 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	size_t		width;
	size_t		length;
	int			**map;
}	t_map;

char	***free_string_map(char ***map);
int		**free_int_map(int **map);
int		parse_map(t_map **map, char *path);


#endif
