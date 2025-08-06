/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:43:37 by kkido             #+#    #+#             */
/*   Updated: 2025/06/06 16:22:06 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*record[1048576];
	char		*result;
	ssize_t		read_result;

	result = NULL;
	read_result = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (record[fd])
	{
		result = ft_strdup_for_gnl(record[fd]);
		if (!result)
			return (reset_gnl(&record[fd], NULL, &result));
		if (check_line_break(record[fd]) != -1)
		{
			if (make_record_and_free(&record[fd], &record[fd]) == -1)
				return (reset_gnl(&record[fd], NULL, &result));
			return (result);
		}
		free(record[fd]);
		record[fd] = NULL;
	}
	return (get_next_line_from_fd(fd, &result, &record[fd], read_result));
}

char	*get_next_line_from_fd(int fd, char **result, char **record,
		ssize_t read_result)
{
	char	*buf;
	char	*tmp;

	buf = NULL;
	while (read_result > 0)
	{
		read_result = malloc_and_read_for_gnl(fd, &buf);
		if (read_result == 0 || read_result == -1)
			return (return_eof_or_error(read_result, result, record, &buf));
		if (*result)
			tmp = ft_strjoin_for_gnl(*result, buf);
		else
			tmp = ft_strdup_for_gnl(buf);
		free(*result);
		*result = NULL;
		if (!tmp)
			return (reset_gnl(record, &buf, result));
		*result = tmp;
		if (check_line_break(buf) != -1)
			break ;
	}
	if (make_record_and_free(record, &buf) == -1)
		return (reset_gnl(record, &buf, result));
	return (*result);
}

char	*return_eof_or_error(ssize_t read_result, char **result, char **record,
		char **buf)
{
	if (read_result == 0)
	{
		if ((*result) && (*result)[0] != '\0')
			return (*result);
		free(*result);
		(*result) = NULL;
		return (NULL);
	}
	return (reset_gnl(record, buf, result));
}

ssize_t	make_record_and_free(char **record, char **str)
{
	size_t	strlen;
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	strlen = ft_strlen_for_gnl(*str, 0);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		i++;
	tmp = malloc((strlen - i) + 1);
	if (!tmp)
		return (-1);
	while (i < strlen)
		tmp[j++] = (*str)[i++];
	tmp[j] = '\0';
	if (*str)
		free(*str);
	*str = NULL;
	if (record != str && *record)
		free(*record);
	*record = tmp;
	return (0);
}

ssize_t	check_line_break(const char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0' && str[i])
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (-1);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*line;
// 	int		fd1;
// 	int		fd2;
// 	int		i;

// 	i = 0;
// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	while (i < 3)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%d:%s", i + 1, line);
// 		free(line);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 3)
// 	{
// 		line = get_next_line(fd2);
// 		printf("%d:%s", i + 1, line);
// 		free(line);
// 		i++;
// 	}
// 	while (i < 3)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%d:%s", i + 1, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
