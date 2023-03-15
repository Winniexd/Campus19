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

# include <unistd.h>

void	ft_hexdump(int *fd, char *buf, int offset);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_display_error(char *str);

#endif
