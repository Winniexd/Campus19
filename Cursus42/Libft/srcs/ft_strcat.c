/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:27:38 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/07 11:27:41 by mdreesen         ###   ########.fr       */
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
