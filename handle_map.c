/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:57:13 by kkido             #+#    #+#             */
/*   Updated: 2025/09/28 17:27:57 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map_from_file(char *map_name)
{
	size_t	i;
	int		fd;
	char	**map_result;
	size_t	line_count;

	i = 0;
	line_count = count_map_lines(map_name);
	if (line_count == 0)
		free_and_exit(4, NULL);
	map_result = malloc(sizeof(char *) * (line_count + 1));
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		free_and_exit(3, NULL);
	while (i < line_count)
	{
		map_result[i] = get_next_line(fd, 0);
		i++;
	}
	map_result[i] = NULL;
	close(fd);
	get_next_line(fd, 1);
	map_error_check(map_result, i);
	return (map_result);
}

size_t	count_map_lines(char *map_name)
{
	int		fd;
	size_t	count;
	char	*line;

	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		free_and_exit(3, NULL);
	line = get_next_line(fd, 0);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
	get_next_line(fd, 1);
	return (count);
}

void	map_error_check(char **map, size_t culumn)
{
	size_t		row;
	size_t		row_index;
	size_t		culumn_index;
	t_mapstate	mapstate;

	mapstate.c_count = 0;
	mapstate.e_count = 0;
	mapstate.p_count = 0;
	row = 0;
	culumn_index = 0;
	row_index = 0;
	if (culumn < 2)
		free_and_exit(4, map);
	row = check_first_and_last_line(map[culumn_index++], row);
	while (row != 0 && culumn_index < culumn)
		mapstate = check_mid_line(map[culumn_index++], &row, mapstate);
	if (row == 0)
		free_and_exit(4, map);
	row = check_first_and_last_line(map[culumn_index - 1], row);
	if (row == 0 || mapstate.c_count < 1 || mapstate.e_count != 1
		|| mapstate.p_count != 1)
		free_and_exit(4, map);
}

size_t	check_first_and_last_line(char *line, size_t row)
{
	size_t	row_index;

	row_index = 0;
	while (line[row_index] && line[row_index + 1] != '\n')
	{
		if (line[row_index] != '1')
		{
			return (0);
		}
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
		(*row) = 0;
	row_index++;
	while (line[row_index] && row_index < (*row))
	{
		if (line[row_index] == 'C')
			mapstate.c_count++;
		else if (line[row_index] == 'E')
			mapstate.e_count++;
		else if (line[row_index] == 'P')
			mapstate.p_count++;
		else if (line[row_index] != '0' && line[row_index] != '1')
			(*row) = 0;
		row_index++;
	}
	if (line[row_index] != '1')
		(*row) = 0;
	if ((*row) != row_index)
		(*row) = 0;
	return (mapstate);
}
