/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:57:59 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 12:40:21 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*input_words(char const *s, char *res, unsigned int start,
				size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (start + len <= ft_strlen(s))
		res = malloc(len + 1);
	else
		res = malloc((ft_strlen(s) - start) + 1);
	if (!res)
		return (NULL);
	return (input_words(s, res, start, len));
}

static char	*input_words(char const *s, char *res, unsigned int start,
		size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[i] != '\0')
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*substr;

// 	str = "Hello, world!";
// 	substr = ft_substr(str, 12, 5);
// 	if (substr)
// 		printf("%s\n", substr);
// 	return (0);
// }
