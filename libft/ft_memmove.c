/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:39:18 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 12:37:48 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overcheck(unsigned char *tmp1, unsigned char *tmp2, size_t n);
static void	mem_over(unsigned char *tmp1, unsigned char *tmp2, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (dst == NULL || src == NULL)
		return (NULL);
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (overcheck(tmp1, tmp2, n) == 0)
	{
		i = 0;
		while (i < n)
		{
			tmp1[i] = tmp2[i];
			i++;
		}
	}
	else
		mem_over(tmp1, tmp2, n);
	return (dst);
}

static void	mem_over(unsigned char *tmp1, unsigned char *tmp2, size_t n)
{
	while (n > 0)
	{
		n--;
		tmp1[n] = tmp2[n];
	}
}

static int	overcheck(unsigned char *tmp1, unsigned char *tmp2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (tmp1 == tmp2 + i)
			return (1);
		i++;
	}
	return (0);
}

// #include <string.h>

// int	main(void)
// {
// 	char	dst1[] = "Hello, world!";
// 	char	dst2[] = "Hello, world!";

// 	ft_memmove(dst1 + 2, dst1, 7);
// 	memmove(dst2 + 2, dst2, 7);
// 	printf("%s\n%s\n", dst1, dst2);
// }
