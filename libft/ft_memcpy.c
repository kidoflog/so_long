/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:20:27 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 12:58:11 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (n != 0 && (dst == NULL || src == NULL))
		return (NULL);
	i = 0;
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dst);
}

// #include <string.h>

// int	main(void)
// {
// 	char	src[] = "Hello, World!";
// 	char	dst1[] = "testtesttesttesttest";
// 	char	dst2[] = "testtesttesttesttest";

// 	ft_memcpy(dst1, src, 5);
// 	memcpy(dst2, src, 5);
// 	printf("%s\n%s\n", dst1, dst2);
// }
