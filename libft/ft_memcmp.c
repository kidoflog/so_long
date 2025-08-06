/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:39:28 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 11:21:29 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	if (n == 0)
		return (0);
	i = 0;
	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	while (tmps1[i] == tmps2[i] && i + 1 < n)
		i++;
	return (tmps1[i] - tmps2[i]);
}

// #include <string.h>

// int	main(void)
// {
// 	const char	str1[] = "zyxbcdefgh";
// 	const char	str2[] = "abcdefgxyz";
// 	size_t		n;

// 	n = 0;
// 	printf("%d\n%d\n", ft_memcmp(str1, str2, n), memcmp(str1, str2, n));
// }
