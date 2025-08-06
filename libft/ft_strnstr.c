/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:54:23 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 12:40:06 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_word(const char *s1, const char *s2);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i + ft_strlen(needle) <= len)
	{
		if (check_word(&haystack[i], needle) >= 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

static int	check_word(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s2[i] == '\0')
		return (i);
	return (-1);
}

// int	main(void)
// {
// 	char	haystack[] = "Hello, world!";
// 	char	needle[] = "world";
// 	size_t	len;

// 	len = 12;
// 	printf("%s\n", ft_strnstr(haystack, needle, len));
// }
