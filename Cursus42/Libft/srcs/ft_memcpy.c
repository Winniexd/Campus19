/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:20:38 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/07 11:56:36 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
}
