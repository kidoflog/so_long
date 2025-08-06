/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:13:46 by kkido             #+#    #+#             */
/*   Updated: 2025/05/17 17:45:45 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = NULL;
	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	if (size == 0 || nmemb == 0)
		return (ft_strdup(""));
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

// int	main(void)
// {
// 	int		*arr;
// 	size_t	i;
// 	size_t	num_elements;

// 	num_elements = 10;
// 	arr = (int *)ft_calloc(num_elements, sizeof(int));
// 	if (arr != NULL)
// 	{
// 		for (i = 0; i < num_elements; i++)
// 		{
// 			printf("arr[%zu] = %d\n", i, arr[i]);
// 		}
// 		free(arr);
// 	}
// }
