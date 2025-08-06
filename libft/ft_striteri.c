/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:38:11 by kkido             #+#    #+#             */
/*   Updated: 2025/05/03 11:02:56 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void	to_lowercase(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = tolower((unsigned char)*c);
// }

// int	main(void)
// {
// 	char	str[] = "HeLLo, WoRLd!";

// 	ft_striteri(str, to_lowercase);
// 	printf("%s\n", str);
// 	return (0);
// }
