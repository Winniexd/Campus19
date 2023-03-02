/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:03:05 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/02 08:59:32 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				len;

	i = 0;
	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[i] != '\0' && i < nb)
	{
		dest[len] = src[i];
		i++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
