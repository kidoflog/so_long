/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   (ft_lstiter.c)_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:46:17 by kkido             #+#    #+#             */
/*   Updated: 2025/05/04 14:48:58 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!lst || !f)
		return ;
	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}

// void	mark_content(void *content)
// {
// 	char	*str;

// 	str = (char *)content;
// 	if (str && str[0] != '\0')
// 		str[0] = '*';
// }

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*tmp;

// 	node1 = malloc(sizeof(t_list));
// 	node2 = malloc(sizeof(t_list));
// 	node3 = malloc(sizeof(t_list));
// 	node1->content = strdup("Apple");
// 	node2->content = strdup("Banana");
// 	node3->content = strdup("Cherry");
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;
// 	ft_lstiter(node1, mark_content);
// 	tmp = node1;
// 	while (tmp)
// 	{
// 		printf("  %s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// }
