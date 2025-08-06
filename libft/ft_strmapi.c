/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:18:01 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 11:04:33 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	char	*res;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	res = malloc(s_len + 1);
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <ctype.h>

// char	alternate_case(unsigned int i, char c)

// {
// 	if (i % 2 == 0)
// 		return (toupper((unsigned char)c));
// 	else
// 		return (tolower((unsigned char)c));
// }

// int	main(void)
// {
// 	const char	*original = "Hello, World!";
// 	char		*mapped;

// 	mapped = ft_strmapi(original, alternate_case);
// 	if (mapped != NULL)
// 		printf("%s\n", mapped);
// }
