/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:58:22 by kkido             #+#    #+#             */
/*   Updated: 2025/08/06 16:23:40 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	void	*mlx_ptr;
	char	**map;
	size_t	i;

	i = 0;
	(void)argv;
	if (argc != 2)
		error_message_and_exit(1);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		error_message_and_exit(2);
	mlx_new_window(mlx_ptr, 1280, 1280, "so_long");
	map = get_map_from_file(argv[1]);
}
