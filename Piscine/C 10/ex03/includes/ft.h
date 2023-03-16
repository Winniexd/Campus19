/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:57:54 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/15 19:50:29 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_hexdump(int *fd, char *buf, int offset);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_display_error(char *str);
void	yolo(char *buf, int len, char *prev_buff, int offset);

void	ft_display_error(char *str);
void	ft_offset(int offset);
void	ft_print_hex(char *buf, int len);
void	ft_print_char(char *buf, int len);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

#endif
