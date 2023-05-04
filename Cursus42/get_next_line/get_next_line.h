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
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(char *str, char c);
char *ft_strdup(char *s1);
char *ft_strncat(char *dest, char *src, int n);
char *ft_substr(char *s, unsigned int start, size_t len);
size_t ft_strlen(const char *str);

#endif