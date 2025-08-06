/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:14:51 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 10:59:55 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!buf)
		return (NULL);
	str = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		str[i] = ch;
		i++;
	}
	return (buf);
}

// #include <string.h>

// int	main(void)
// {
// 	char	buffer1[20] = "Hello, world!";
// 	char	buffer2[20] = "Hello, world!";

// 	ft_memset(buffer1, 'A', 5);
// 	memset(buffer2, 'A', 5);
// 	printf("%s\n%s\n", buffer1, buffer2);
// }
