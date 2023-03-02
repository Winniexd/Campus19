/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:29:59 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/02 08:40:13 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len1;
	unsigned int	len2;

	i = 0;
	j = 0;
	len1 = 0;
	len2 = 0;
	while (dest[len1] != '\0' && len1 < size)
		len1++;
	while (src[len2] != '\0')
		len2++;
	if (len1 == size)
		return (size + len2);
	while (src[j] != '\0' && i + len1 + 1 < size)
	{
		dest[len1 + i] = src[j];
		i++;
		j++;
	}
	dest[len1 + i] = '\0';
	return (len1 + len2);
}
