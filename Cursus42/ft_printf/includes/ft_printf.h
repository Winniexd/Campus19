/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:38:40 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/18 11:38:41 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	len;
	int	written;
}		t_data;

int		ft_printf(const char *format, ...);
void	ft_putstr(char *str);
int		ft_numlen(int num);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr(int num);
void	ft_putchar(char c);
char	*ft_strchr(const char *s);

#endif
