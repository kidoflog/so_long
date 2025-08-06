/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:12:04 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 11:05:35 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	tmp;

	if (!s)
		return (NULL);
	tmp = c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (0 <= i && s[i] != tmp)
		i--;
	if (s[i] == tmp)
		return ((char *)&s[i]);
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "Hello, world!";
// 	int		c;

// 	c = 108;
// 	printf("%s\n", ft_strrchr("abc", 'z'));
// }
