/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:26:06 by kkido             #+#    #+#             */
/*   Updated: 2025/05/04 14:50:38 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*res;

// 	res = malloc(sizeof(t_list));
// 	if (!res)
// 		return (NULL);
// 	res->content = content;
// 	res->next = NULL;
// 	return (res);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;

// 	head = ft_lstnew("First");
// 	node1 = ft_lstnew("Second");
// 	node2 = ft_lstnew("Third");
// 	node1->next = node2;
// 	head->next = node1;
// 	printf("%d\n", ft_lstsize(head));
// 	return (0);
// }
