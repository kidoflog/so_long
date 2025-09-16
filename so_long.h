/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:15:30 by kkido             #+#    #+#             */
/*   Updated: 2025/09/09 10:35:08 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx_mms_20191025_beta/mlx.h"
# include <fcntl.h>

void		free_and_exit(size_t id, char **map);
char		**get_map_from_file(char *map_name);
void		map_error_check(char **map, size_t culumn);
size_t		check_first_and_last_line(char *line, size_t row);
t_mapstate	check_mid_line(char *line, size_t *row, t_mapstate mapstate);
typedef struct s_mapstate
{
	size_t	e_count;
	size_t	p_count;
	size_t	c_count;
}			t_mapstate;

typedef struct s_mlxstate
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlxstate;

#endif
