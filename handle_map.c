/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:57:13 by kkido             #+#    #+#             */
/*   Updated: 2025/09/09 10:33:31 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map_from_file(char *map_name)
{
	size_t	i;
	int		fd;
	char	**map_result;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		free_and_exit(3, NULL);
	map_result[i] == get_next_line(fd);
	while (map_result[i])
	{
		i++;
		map_result[i] == get_next_line(fd);
	}
	close(fd);
	map_error_check(map_result, i);
	return (map_result);
}

void	map_error_check(char **map, size_t culumn)
{
	size_t		row;
	size_t		row_index;
	t_mapstate	mapstate;

	mapstate.c_count = 0;
	mapstate.e_count = 0;
	mapstate.p_count = 0;
	row = 0;
	row_index = 0;
	if (culumn < 2)
		free_and_exit(4, map);
	culumn = 0;
	row = check_first_and_last_line(map[culumn++], row);
	while (row != 0 && map[culumn + 1])
		mapstate = check_mid_line(map[culumn++], &row, mapstate);
	if (row == 0 || mapstate.c_count > 0 || mapstate.e_count != 1
		|| mapstate.p_count != 1)
		free_and_exit(4, map);
	row = check_first_and_last_line(map[culumn], row);
}

size_t	check_first_and_last_line(char *line, size_t row)
{
	size_t	row_index;

	row_index = 0;
	while (line[row_index])
	{
		if (line[row_index] != '1')
			return (0);
		row_index++;
	}
	if (row_index < 2)
		return (0);
	if (row == 0)
		return (row_index);
	else if (row != row_index)
		return (0);
	return (row_index);
}

t_mapstate	check_mid_line(char *line, size_t *row, t_mapstate mapstate)
{
	size_t	row_index;

	row_index = 0;
	if (line[row_index] != '1')
		(row) = 0;
	row_index++;
	while (line[row_index + 1])
	{
		if (line[row_index] == 'C')
			mapstate.c_count++;
		if (line[row_index] == 'E')
			mapstate.e_count++;
		if (line[row_index] == 'P')
			mapstate.p_count++;
		else if (line[row_index] != '0' && line[row_index] != '1')
			(row) = 0;
		row_index++;
	}
	if (line[row_index] != '1')
		(row) = 0;
	row_index++;
	if (row != row_index)
		(row) = 0;
	return (mapstate);
}
