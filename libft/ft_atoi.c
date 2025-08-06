/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:08:31 by kkido             #+#    #+#             */
/*   Updated: 2025/05/05 17:37:33 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_space(int i, const char *str);
static int	overflow_check(int i, const char *str, int sign);
static int	ten_overflow_check(int i, const char *str, int sign);

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	i = skip_space(i, str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (overflow_check(i, str, sign) == 1)
		return (INT_MAX);
	if (overflow_check(i, str, sign) == -1)
		return (INT_MIN);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	skip_space(int i, const char *str)
{
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

static int	overflow_check(int i, const char *str, int sign)
{
	int	count;

	count = 0;
	while (str[i] == '0')
		i++;
	while (str[i + count] <= '9' && str[i + count] >= '0')
		count++;
	if (sign == 1)
	{
		if (count > 10 || (count == 10 && ten_overflow_check(i, str,
					sign) == 1))
			return (1);
	}
	else
	{
		if (count > 10 || (count == 10 && ten_overflow_check(i, str,
					sign) == 1))
			return (-1);
	}
	return (0);
}

static int	ten_overflow_check(int i, const char *str, int sign)
{
	int	result;
	int	count;

	count = 0;
	result = 0;
	while (count < 9)
	{
		result = result * 10 + (str[i + count] - '0');
		count++;
	}
	if (result > 214748364)
		return (1);
	if (result == 214748364)
	{
		if (sign == 1 && ('7' <= str[i + count] && '9' >= str[i + count]))
			return (1);
		if (sign == -1 && ('8' <= str[i + count] && '9' >= str[i + count]))
			return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d",
// 		ft_atoi("+0000000000000000000000000000000000000000000000000000123"));
// }
