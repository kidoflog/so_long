/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:26:11 by kkido             #+#    #+#             */
/*   Updated: 2025/08/06 16:35:01 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message_and_exit(size_t id)
{
	if (id == 1)
		ft_printf("Usage: ./so_long \"mapfile\"\n");
	else if (id == 2)
		ft_printf("Error: failed to make window\n");
	else if (id == 3)
		ft_printf("Error: failed to open mapfile\n");
	else if (id == 4)
		ft_printf("Error: failed to read mapfile or invalid map\n");
	exit(1);
}
