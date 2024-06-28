/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:34:28 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/12 15:34:29 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *s1);
char	*ft_strncat(char *dest, char *src, int n);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_free(char **str);
char	*ft_join(char *ptr, char *start, char *buff);
char	*ft_parse(char *start);
char	*ft_move_start(char *start);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif