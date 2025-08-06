/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:37:17 by kkido             #+#    #+#             */
/*   Updated: 2025/05/05 14:59:07 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
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

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*last_node;

// 	head = NULL;
// 	node1 = ft_lstnew("First");
// 	node2 = ft_lstnew("Second");
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node1);
// 	last_node = ft_lstlast(head);
// 	if (last_node)
// 		printf("%s\n", (char *)last_node->content);
// }
