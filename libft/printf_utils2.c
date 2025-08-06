/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:35:27 by kkido             #+#    #+#             */
/*   Updated: 2025/06/06 16:18:39 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <unistd.h>

int	format_u_fanc_for_printf(unsigned int num, int bytes_count)
{
	char	digits[11];

	ft_strlcpy(digits, "0123456789", 11);
	if (num >= 10)
		bytes_count = format_u_fanc_for_printf(num / 10, bytes_count);
	if (bytes_count < 0)
		return (bytes_count);
	if (write(1, &digits[num % 10], 1) < 0)
		return (-1);
	return (bytes_count + 1);
}

int	format_x_fanc_for_printf(unsigned int num, int bytes_count)
{
	int	result;

	result = print_in_hex_for_printf((unsigned long)num);
	if (result < 0)
		return (result);
	return ((bytes_count + result));
}

int	format_upper_x_fanc_for_printf(unsigned int num, int bytes_count)
{
	int	result;

	result = print_in_upper_hex_for_printf((unsigned long)num);
	if (result < 0)
		return (result);
	return ((bytes_count + result));
}

int	print_in_upper_hex_for_printf(unsigned long num)
{
	char	upper_hex[17];
	int		write_result;

	write_result = 0;
	ft_strlcpy(upper_hex, "0123456789ABCDEF", 17);
	if (num >= 16)
		write_result = print_in_upper_hex_for_printf(num / 16);
	if (write_result < 0)
		return (write_result);
	if (write(1, &upper_hex[num % 16], 1) < 0)
		return (-1);
	return (write_result + 1);
}

int	format_percent_fanc_for_printf(int bytes_count)
{
	if (write(1, "%", 1) < 0)
		return (-1);
	return (bytes_count + 1);
}
