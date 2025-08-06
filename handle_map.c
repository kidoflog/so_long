/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:57:13 by kkido             #+#    #+#             */
/*   Updated: 2025/08/06 17:17:07 by kkido            ###   ########.fr       */
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
		error_message_and_exit(3);
	map_result[i] == get_next_line(fd);
	while (map_result[i])
	{
		i++;
		map_result[i] == get_next_line(fd);
	}
	map_error_check(map_result, i);
	return (map_result);
}

void	map_error_check(char **map, size_t culumn)
{
	size_t	row;
	size_t	row_index;

	row = 0;
	row_index = 0;
	if (culumn < 2)
		error_message_and_exit(4);
	culumn = 0;
	row = check_first_and_last_line(map[culumn], row);
	while (map[culumn + 1])
	{
		if (map[culumn][row] != '0' && map[culumn][row] != '1'
			&& map[culumn][row] != 'C' && map[culumn][row] != 'E'
			&& map[culumn][row] != 'P')
			error_message_and_exit(4);
	}
}

size_t	check_first_and_last_line(char *line, size_t row)
{
	size_t	row_index;

	row_index = 0;
	while (line[row_index])
	{
		if (line[row_index] != '1')
			error_message_and_exit(4);
		row_index++;
	}
	if (row_index < 3)
		error_message_and_exit(4);
	if (row == 0)
		return (row_index);
	else if (row != row_index)
		error_message_and_exit(4);
	return (0);
}
