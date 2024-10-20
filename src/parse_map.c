/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:24:01 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/20 09:20:39 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_list	*read_file(int fd)
{
	char	*new_line;
	t_list	*new_node;
	t_list	*lst;

	if (fd == -1)
		return (NULL);
	lst = NULL;
	new_line = get_next_line(fd);
	while (new_line)
	{
		new_node = ft_lstnew((void *) new_line);
		if (!new_node)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		ft_lstadd_back(&lst, new_node);
		new_line = get_next_line(fd);
	}
	return (lst);
}

static char	***create_str_map(t_list *lines)
{
	char	***string_map;
	size_t	i;

	if (!lines)
		return (NULL);
	string_map = ft_calloc(ft_lstsize(lines) + 1, sizeof (char **));
	if (!string_map)
		return (NULL);
	i = 0;
	while (lines)
	{
		string_map[i] = ft_split((char *) lines->content, ' ');
		if (!string_map[i])
			return (free_string_map(string_map));
		++i;
		lines = lines->next;
	}
	return (string_map);
}

static int	**convert_map(char ***str_map, size_t map_length, size_t map_width)
{
	size_t	i;
	size_t	j;
	int		**int_map;

	int_map = ft_calloc(map_length + 1, sizeof (int *));
	if (!int_map)
		return (NULL);
	i = 0;
	while (i < map_length)
	{
		int_map[i] = ft_calloc(map_width + 1, sizeof (int));
		if (!int_map[i])
			return (free_int_map(int_map));
		j = 0;
		while (j < map_width)
		{
			int_map[i][j] = ft_atoi(str_map[i][j]);
			++j;
		}
		++i;
	}
	return (int_map);
}

static void	init_map(char ***str_map, t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (!(*map))
		return ;
	if (!get_map_sizes(*map, str_map))
	{
		free (map);
		*map = NULL;
		return ;
	}
	(*map)->map = convert_map(str_map, (*map)->length, (*map)->width);
	(*map)->projection = NULL;
	if (!(*map)->map)
	{
		free (*map);
		*map = NULL;
	}
}

int	parse_map(t_map **map, char *path)
{
	int			fd;
	t_list		*file_by_line;
	char		***str_map;


	fd = open(path, O_RDONLY);
	file_by_line = read_file(fd);
	str_map = create_str_map(file_by_line);
	init_map(str_map, map);
	ft_lstclear(&file_by_line, free);
	free_string_map(str_map);
	if (!(*map))
		return (0);
	return (1);
}
