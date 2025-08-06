/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:56:12 by kkido             #+#    #+#             */
/*   Updated: 2025/05/04 14:50:27 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*my_mapclear(t_list **lst, void (*del)(void *));
static t_list	*cp_and_func_map(t_list *current_lst, void *(*f)(void *),
					void (*del)(void *), t_list *res);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*current_lst;

	if (!lst || !f || !del)
		return (NULL);
	current_lst = lst;
	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = NULL;
	res->next = NULL;
	current_lst = lst;
	return (cp_and_func_map(current_lst, f, del, res));
}

static t_list	*cp_and_func_map(t_list *current_lst, void *(*f)(void *),
		void (*del)(void *), t_list *res)
{
	t_list	*current_res;
	t_list	*new_res;

	current_res = res;
	while (current_lst != NULL)
	{
		current_res->content = f(current_lst->content);
		if (!(current_res->content))
			return (my_mapclear(&res, del));
		if (current_lst->next == NULL)
			current_res->next = NULL;
		else
		{
			new_res = malloc(sizeof(t_list));
			if (!(new_res))
				return (my_mapclear(&res, del));
			current_res->next = new_res;
			current_res = new_res;
		}
		current_lst = current_lst->next;
	}
	return (res);
}

static void	*my_mapclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_lst;

	current = *lst;
	while (current != NULL)
	{
		next_lst = current->next;
		if (current->content)
			del(current->content);
		free(current);
		current = next_lst;
	}
	*lst = NULL;
	return (NULL);
}

// void	*map_to_upper(void *content)
// {
// 	char	*str;

// 	str = (char *)content;
// 	for (int i = 0; str[i]; i++)
// 		str[i] = str[i] - 32 * (str[i] >= 'a' && str[i] <= 'z');
// 	return (content);
// }

// void	delete_content(void *content)
// {
// 	free(content);
// }

// t_list	*create_node(char *str)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->content = ft_strdup(str);
// 	node->next = NULL;
// 	return (node);
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

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new_list;

// 	head = create_node("hello");
// 	head->next = create_node("world");
// 	head->next->next = create_node("libft");
// 	print_list(head);
// 	new_list = ft_lstmap(head, map_to_upper, delete_content);
// 	print_list(new_list);
// }
