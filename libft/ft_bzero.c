/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:08:27 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 10:55:31 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return ;
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

// #include <string.h>

// int	main(void)
// {
// 	char	buffer1[20] = "Hello, world!";
// 	char	buffer2[20] = "Hello, world!";

// 	ft_bzero(buffer1, 5);
// 	bzero(buffer2, 5);
// 	printf("%s\n%s\n", buffer1, buffer2);
// }
