/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:29:21 by kkido             #+#    #+#             */
/*   Updated: 2025/06/06 16:19:42 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *buf, int ch, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new_lst);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
char				*get_next_line_from_fd(int fd, char **result, char **record,
						ssize_t read_result);
char				*reset_gnl(char **record, char **buf, char **result);
char				*ft_strdup_for_gnl(const char *s1);
char				*ft_strjoin_for_gnl(char const *s1, char const *s2);
ssize_t				ft_strlen_for_gnl(const char *str, int stop_count);
ssize_t				malloc_and_read_for_gnl(int fd, char **buf);
ssize_t				check_line_break(const char *str);
ssize_t				make_record_and_free(char **record, char **str);
char				*return_eof_or_error(ssize_t read_result, char **result,
						char **record, char **buf);
int					ft_printf(const char *str, ...);
int					handle_format_for_printf(const char *str, int bytes_count,
						va_list *args);
int					format_c_fanc_for_printf(int n, int bytes_count);
int					format_s_fanc_for_printf(char *str, int bytes_count);
int					format_p_fanc_for_printf(void *str, int bytes_count);
int					print_in_hex_for_printf(unsigned long num);
int					format_d_i_fanc_for_printf(int num, int bytes_count);
int					format_u_fanc_for_printf(unsigned int num, int bytes_count);
int					format_x_fanc_for_printf(unsigned int num, int bytes_count);
int					format_upper_x_fanc_for_printf(unsigned int num,
						int bytes_count);
int					print_in_upper_hex_for_printf(unsigned long num);
int					format_percent_fanc_for_printf(int bytes_count);

#endif
