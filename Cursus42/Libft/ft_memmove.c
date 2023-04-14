/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:23:03 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/07 11:23:04 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memmove(void *dest, const void *src, int len)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr > src_ptr && dest_ptr < src_ptr + len)
	{
		dest_ptr += len;
		src_ptr += len;
		while (len--)
		{
			*(--dest_ptr) = *(--src_ptr);
		}
	}
	else
	{
		while (len--)
		{
			*(dest_ptr++) = *(src_ptr++);
		}
	}
}
