/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:27:04 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 11:02:22 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	tmp;

	i = 0;
	tmp = c;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != tmp)
		i++;
	if (s[i] == tmp)
		return ((char *)&s[i]);
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "Hello, world!";
// 	int		c;

// 	c = 33;
// 	printf("%s\n", ft_strchr(s, c + 256));
// }
