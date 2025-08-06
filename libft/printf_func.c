/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:41:44 by kkido             #+#    #+#             */
/*   Updated: 2025/06/06 16:21:19 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		bytes_count;

	if (!str)
		return (-1);
	va_start(args, str);
	bytes_count = 0;
	while (*str != '\0' && bytes_count >= 0)
	{
		if (*str == '%')
		{
			str++;
			bytes_count = handle_format_for_printf(str, bytes_count, &args);
		}
		else
		{
			if (write(1, str, 1) < 0)
				return (va_end(args), -1);
			bytes_count++;
		}
		str++;
	}
	return (va_end(args), bytes_count);
}

int	handle_format_for_printf(const char *str, int bytes_count, va_list *args)
{
	if (*str == 'c')
		return (format_c_fanc_for_printf(va_arg(*args, int), bytes_count));
	if (*str == 's')
		return (format_s_fanc_for_printf(va_arg(*args, char *), bytes_count));
	if (*str == 'p')
		return (format_p_fanc_for_printf(va_arg(*args, void *), bytes_count));
	if (*str == 'd')
		return (format_d_i_fanc_for_printf(va_arg(*args, int), bytes_count));
	if (*str == 'i')
		return (format_d_i_fanc_for_printf(va_arg(*args, int), bytes_count));
	if (*str == 'u')
		return (format_u_fanc_for_printf(va_arg(*args, unsigned int),
				bytes_count));
	if (*str == 'x')
		return (format_x_fanc_for_printf(va_arg(*args, unsigned int),
				bytes_count));
	if (*str == 'X')
		return (format_upper_x_fanc_for_printf(va_arg(*args, unsigned int),
				bytes_count));
	if (*str == '%')
		return (format_percent_fanc_for_printf(bytes_count));
	return (-1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		n1;
// 	int		n2;
// 	char	c;
// 	char	str[7] = "world!";

// 	c = 'H';
// 	printf("nomal\n");
// 	n1 = ft_printf("Hello, world!");
// 	printf(" %d\n", n1);
// 	n2 = printf("Hello, world!");
// 	printf(" %d\n", n2);
// 	printf("%%c\n");
// 	n1 = ft_printf("%c", c);
// 	printf(" %d\n", n1);
// 	n2 = printf("%c", c);
// 	printf(" %d\n", n2);
// 	printf("%%s\n");
// 	n1 = ft_printf("Hello, %s", str);
// 	printf(" %d\n", n1);
// 	n2 = printf("Hello, %s", str);
// 	printf(" %d\n", n2);
// 	printf("%%p\n");
// 	n1 = ft_printf("%p", str);
// 	printf(" %d\n", n1);
// 	n2 = printf("%p", str);
// 	printf(" %d\n", n2);
// 	printf("%%d\n");
// 	n1 = ft_printf("Hello, %d %d %d %d!", 42, -42, 2147483647, -2147483647);
// 	printf(" %d\n", n1);
// 	n2 = printf("Hello, %d %d %d %d!", 42, -42, 2147483647, -2147483647);
// 	printf(" %d\n", n2);
// 	printf("%%i\n");
// 	n1 = ft_printf("Hello, %i %i %i %i!", 42, -42, 2147483647, -2147483647);
// 	printf(" %d\n", n1);
// 	n2 = printf("Hello, %i %i %i %i!", 42, -42, 2147483647, -2147483647);
// 	printf(" %d\n", n2);
// 	printf("%%u\n");
// 	n1 = ft_printf("Hello, %u %u %u!", 42, 0, 4294967295u);
// 	printf(" %d\n", n1);
// 	n2 = printf("Hello, %u %u %u!", 42, 0, 4294967295u);
// 	printf(" %d\n", n2);
// 	printf("%%x\n");
// 	n1 = ft_printf("Hello, %x %x %x!", 42, 0, 4294967295u);
// 	printf(" %d\n", n1);
// 	n2 = printf("Hello, %x %x %x!", 42, 0, 4294967295u);
// 	printf(" %d\n", n2);
// 	printf("%%X\n");
// 	n1 = ft_printf("Hello, %X %X %X!", 42, 0, 4294967295u);
// 	printf(" %d\n", n1);
// 	n2 = printf("Hello, %X %X %X!", 42, 0, 4294967295u);
// 	printf(" %d\n", n2);
// 	printf("%%\n");
// 	n1 = ft_printf("Hello, %%42!");
// 	printf(" %d\n", n1);
// 	n2 = printf("Hello, %%42!");
// 	printf(" %d\n", n2);
// 	printf("error handling\n");
// 	n1 = ft_printf(NULL);
// 	printf(" %d\n", n1);
// 	n2 = printf(NULL);
// 	printf(" %d\n", n2);
// }
