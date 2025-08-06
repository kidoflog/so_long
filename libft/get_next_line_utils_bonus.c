/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:43:34 by kkido             #+#    #+#             */
/*   Updated: 2025/06/06 16:21:59 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_for_gnl(const char *s1)
{
	size_t	len;
	char	*copy;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen_for_gnl(s1, 1);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

ssize_t	ft_strlen_for_gnl(const char *str, int stop_count)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (stop_count == 1 && str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

ssize_t	malloc_and_read_for_gnl(int fd, char **buf)
{
	ssize_t	bytes_read;

	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	*buf = malloc(BUFFER_SIZE + 1);
	if (!*buf)
		return (-1);
	bytes_read = read(fd, *buf, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(*buf);
		*buf = NULL;
		return (bytes_read);
	}
	(*buf)[bytes_read] = '\0';
	return (bytes_read);
}

char	*reset_gnl(char **record, char **buf, char **result)
{
	if (record && *record)
	{
		free(*record);
		*record = NULL;
	}
	if (buf && *buf)
	{
		free(*buf);
		*buf = NULL;
	}
	if (result && *result)
	{
		free(*result);
		*result = NULL;
	}
	return (NULL);
}

char	*ft_strjoin_for_gnl(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;
	size_t	s1_i;
	size_t	s2_i;

	s1_len = ft_strlen_for_gnl(s1, 1);
	s2_len = ft_strlen_for_gnl(s2, 1);
	res = malloc(s1_len + s2_len + 1);
	s1_i = 0;
	s2_i = 0;
	if (!res)
		return (NULL);
	while (s1_i < s1_len)
	{
		res[s1_i] = s1[s1_i];
		s1_i++;
	}
	while (s2_i < s2_len)
		res[s1_i++] = s2[s2_i++];
	res[s1_i] = '\0';
	return (res);
}
