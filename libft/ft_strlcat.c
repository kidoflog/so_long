/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:45:32 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 11:20:36 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i1;
	size_t	i2;
	size_t	ret;

	i1 = 0;
	i2 = 0;
	ret = 0;
	while (src[ret] != '\0')
		ret++;
	while (dst[i1] != '\0')
		i1++;
	if (i1 >= dstsize)
		return (dstsize + ret);
	ret = ret + i1;
	while (i1 + 1 < dstsize && src[i2] != '\0')
		dst[i1++] = src[i2++];
	dst[i1] = '\0';
	return (ret);
}

// int	main(void)
// {
// 	char	dst[20] = "Hello, ";
// 	char	src[20] = "world!";
// 	size_t	res;

// 	res = ft_strlcat(dst, src, 8);
// 	printf("%s\n%zu", dst, res);
// }
