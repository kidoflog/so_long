/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:36:36 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 11:02:35 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1len;
	char	*s2;
	int		i;

	if (!s1)
		return (NULL);
	s1len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (s1len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// int	main(void)
// {
// 	char	*original;
// 	char	*copy;

// 	original = "Hello, world!";
// 	copy = ft_strdup(original);
// 	if (copy != NULL)
// 	{
// 		printf("%s\n", copy);
// 	}
// 	return (0);
// }
