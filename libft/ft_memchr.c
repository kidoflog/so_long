/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:52:09 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 11:21:18 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmps;
	unsigned char	tmp;
	size_t			i;

	if (!s)
		return (NULL);
	if (n == 0)
		return (NULL);
	tmps = (unsigned char *)s;
	tmp = c;
	i = 0;
	while (tmps[i] != tmp && i + 1 < n)
		i++;
	if (tmps[i] == tmp)
		return ((void *)&tmps[i]);
	return (NULL);
}

// int	main(void)
// {
// 	const char	str[] = "s";
// 	char		*result;
// 	int			c;

// 	c = '0';
// 	result = ft_memchr(str, c, sizeof(str));
// 	printf("%s\n", result);
// 	result = memchr(str, c, sizeof(str));
// 	printf("%s\n", result);
// 	return (0);
// }
