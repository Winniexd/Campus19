/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:05:28 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/16 08:05:30 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		check_n_bigger_than_file(char *av, int n);
void	ft_tail(int *fd, int n, char *buf, int len);
void	display_file(int *fd, int n, int len);
int		ft_atoi(char *str);
void	ft_putstr(char *str);

#endif