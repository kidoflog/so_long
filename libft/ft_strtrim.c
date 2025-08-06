/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:30:54 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 12:40:37 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	setcheck(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	finish;
	size_t	s1len;
	size_t	i;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	s1len = ft_strlen(s1);
	if (s1len == 0)
		return (ft_strdup(""));
	start = 0;
	finish = s1len - 1;
	while (setcheck(s1[start], set) == 1 && s1[start] != '\0')
		start++;
	while (finish > start && setcheck(s1[finish], set) == 1)
		finish--;
	res = malloc(finish - start + 2);
	if (!res)
		return (NULL);
	while (finish >= start)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}

static int	setcheck(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*set;
// 	char	*trimmed;

// 	s1 = "lorem ipsum dolor sit amet";
// 	set = "te";
// 	trimmed = ft_strtrim(s1, set);
// 	if (trimmed != NULL)
// 		printf("%s\n", trimmed);
// }
