/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:46:50 by kkido             #+#    #+#             */
/*   Updated: 2025/06/06 16:18:36 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <unistd.h>

int	format_c_fanc_for_printf(int n, int bytes_count)
{
	char	c;

	c = n;
	if (write(1, &c, 1) < 0)
		return (-1);
	return (bytes_count + 1);
}

int	format_s_fanc_for_printf(char *str, int bytes_count)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len] != '\0')
	{
		if (write(1, &str[len], 1) < 0)
			return (-1);
		len++;
	}
	return (bytes_count + len);
}

int	format_p_fanc_for_printf(void *ptr, int bytes_count)
{
	uintptr_t	address;
	int			result;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) < 0)
			return (-1);
		return (bytes_count + 5);
	}
	if (write(1, "0x", 2) < 0)
		return (-1);
	bytes_count += 2;
	address = (uintptr_t)ptr;
	result = print_in_hex_for_printf((unsigned long)address);
	if (result < 0)
		return (-1);
	return (bytes_count + result);
}

int	print_in_hex_for_printf(unsigned long num)
{
	char	hex[17];
	int		write_result;

	write_result = 0;
	ft_strlcpy(hex, "0123456789abcdef", 17);
	if (num >= 16)
		write_result = print_in_hex_for_printf(num / 16);
	if (write_result < 0)
		return (write_result);
	if (write(1, &hex[num % 16], 1) < 0)
		return (-1);
	return (write_result + 1);
}

int	format_d_i_fanc_for_printf(int num, int bytes_count)
{
	char	digits[11];

	if (num == -2147483648)
	{
		if (write(1, "-2147483648", 11) < 0)
			return (-1);
		return (bytes_count + 11);
	}
	if (num < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		num = num * -1;
		bytes_count++;
	}
	ft_strlcpy(digits, "0123456789", 11);
	if (num >= 10)
		bytes_count = format_d_i_fanc_for_printf(num / 10, bytes_count);
	if (bytes_count < 0)
		return (bytes_count);
	if (write(1, &digits[num % 10], 1) < 0)
		return (-1);
	return (bytes_count + 1);
}
