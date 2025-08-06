/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   (ft_lstnew.c)_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:01:22 by kkido             #+#    #+#             */
/*   Updated: 2025/05/04 14:49:45 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

// int	main(void)
// {
// 	char	*str;
// 	t_list	*node;

// 	str = strdup("Hello, world!");
// 	if (!str)
// 		return (1);
// 	node = ft_lstnew(str);
// 	if (node)
// 	{
// 		printf("%s\n", (char *)node->content);
// 		printf("%p\n", node->next);
// 	}
// }
