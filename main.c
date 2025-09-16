/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:58:22 by kkido             #+#    #+#             */
/*   Updated: 2025/09/16 15:03:08 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlxstate	*mlxstate;
	char		**map;
	size_t		i;

	i = 0;
	(void)argv;
	if (argc != 2)
		free_and_exit(1, NULL);
	map = get_map_from_file(argv[1]);
	mlxstate->mlx_ptr = mlx_init();
	if (!mlxstate->mlx_ptr)
		free_and_exit(2, map);
	mlxstate->win_ptr = mlx_new_window(mlxstate->mlx_ptr, 1280, 1280,
			"so_long");
	if (!mlxstate->win_ptr)
		free_and_exit(2, map);
}
