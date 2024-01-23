/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:34:28 by mdreesen          #+#    #+#             */
/*   Updated: 2024/01/23 16:56:14 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *str, int c);
char	*gnl_strdup(char *s1);
char	*ft_strncat(char *dest, char *src, int n);
char	*gnl_substr(char *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_free(char **str);
char	*ft_join(char *ptr, char *start, char *buff);
char	*ft_parse(char *start);
char	*ft_move_start(char *start);
void	*gnl_memcpy(void *dest, const void *src, size_t n);

#endif