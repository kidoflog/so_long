/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:31:17 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 12:39:07 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**input_split(char **res, const char *s, char c);
static int	word_count(char const *s, char c);
static void	*free_all_mem(char **res, size_t i2);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i1;
	size_t	i2;
	size_t	tmp;

	i1 = 0;
	i2 = 0;
	res = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i1] != '\0')
	{
		while (s[i1] == c)
			i1++;
		tmp = i1;
		while (s[i1] != c && s[i1] != '\0')
			i1++;
		if (i1 > tmp)
		{
			res[i2++] = malloc(i1 - tmp + 1);
			if (!res[i2 - 1])
				return (free_all_mem(res, i2));
		}
	}
	return (input_split(res, s, c));
}

static char	**input_split(char **res, const char *s, char c)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;

	i1 = 0;
	i2 = 0;
	while (s[i1] != '\0')
	{
		i3 = 0;
		while (s[i1] == c)
			i1++;
		while (s[i1] != c && s[i1] != '\0')
			res[i2][i3++] = s[i1++];
		if (i3 != 0)
		{
			res[i2][i3] = '\0';
			i2++;
		}
	}
	res[i2] = NULL;
	return (res);
}

static int	word_count(char const *s, char c)
{
	int		count;
	int		flag;
	size_t	i;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (count);
}

static void	*free_all_mem(char **res, size_t i2)
{
	size_t	i1;

	i1 = 0;
	while (i1 < i2)
		free(res[i1++]);
	free(res);
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	charset;
// 	char	**result;
// 	int		index;

// 	str = "Hselslowosrlssd!s";
// 	charset = 's';
// 	result = ft_split(str, charset);
// 	index = 0;
// 	while (result[index])
// 	{
// 		printf("%s\n", result[index]);
// 		free(result[index]);
// 		index++;
// 	}
// 	free(result);
// 	return (0);
// }
