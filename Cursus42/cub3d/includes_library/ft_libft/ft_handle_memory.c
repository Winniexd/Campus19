/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:48:31 by jepatern          #+#    #+#             */
/*   Updated: 2024/05/14 13:09:42 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void *ptr)
{
	void	**ptrv;

	ptrv = ptr;
	if (*ptrv)
		free(*ptrv);
	*ptrv = NULL;
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(size, 1);
	return (ptr);
}
