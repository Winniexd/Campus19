/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:38:40 by mdreesen          #+#    #+#             */
/*   Updated: 2023/06/13 15:17:02 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
int		ft_putnbr_base(unsigned int nbr, char *base);
void	ft_putchar(char c);
char	*my_strchr(const char *s);
char	*ft_itoa_base(unsigned int nbr, char *base);
void	handle_p(t_data *data, va_list args);
void	handle_x(t_data *data, va_list args);
void	handle_cx(t_data *data, va_list args);
void	handle_percent(t_data *data);
void	handle_char(t_data *data, va_list args);
void	handle_string(t_data *data, va_list args);
void	handle_int(t_data *data, va_list args);
void	handle_unsigned_int(t_data *data, va_list args);
size_t	ft_strlen(const char *s);

#endif
