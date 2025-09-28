/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:26:11 by kkido             #+#    #+#             */
/*   Updated: 2025/09/20 14:51:14 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit(size_t id, char **map)
{
	size_t	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	if (id == 1)
		ft_printf("Usage: ./so_long \"mapfile\"\n");
	else if (id == 2)
		ft_printf("Error: failed to make window\n");
	else if (id == 3)
		perror("Error: failed to open mapfile\n");
	else if (id == 4)
		ft_printf("Error: failed to read mapfile or invalid map\n");
	exit(1);
}
