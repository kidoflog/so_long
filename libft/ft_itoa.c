/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:25:01 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 12:36:49 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(int n);
static char	*int_min(void);

char	*ft_itoa(int n)
{
	char	*res;
	int		num;

	if (n == -2147483648)
		return (int_min());
	num = count_char(n);
	res = malloc(num + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n = n * -1;
	}
	res[num] = '\0';
	num--;
	while (n >= 10)
	{
		res[num] = (n % 10) + '0';
		n = n / 10;
		num--;
	}
	res[num] = n + '0';
	return (res);
}

static char	*int_min(void)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	tmp = "-2147483648";
	res = malloc(12);
	if (!res)
		return (NULL);
	while (tmp[i] != '\0')
	{
		res[i] = tmp[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	count_char(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483648LL));
// }
