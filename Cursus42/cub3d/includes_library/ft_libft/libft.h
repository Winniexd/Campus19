/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:14:01 by jepatern          #+#    #+#             */
/*   Updated: 2024/05/22 12:55:35 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX FOPEN_MAX
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(long long n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, void *src, size_t n);
void				*ft_memmove(void *dst, void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char *s, char c, int flag);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(char *s1, int code);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char *s1, char *s2, int flag);
char				*ft_strjoin_gnl(char *s1, char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char *s1, char *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
int					ft_putstr(char *str);
int					ft_tri(char choice, va_list strin);
int					ft_printf(const char *strin, ...);
int					ft_wint(long long nb, int code);
int					ft_wchar(int nb);
int					ft_wstr(char *str);
int					ft_wptr(void *ptr);
int					ft_whex(unsigned long nb, char *base, int code);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strdup(char *s1, int code);
char				*get_next_line(int fd);
int					ft_there_is_c(char *str, char c);
void				ft_putnbr(int nb);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_set_zero(int *a, int *b, int *c, int *d);
int					ft_strdiff(char *s1, char *s2);

#endif