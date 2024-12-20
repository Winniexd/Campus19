/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:39:55 by jepatern          #+#    #+#             */
/*   Updated: 2021/09/11 21:39:56 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*liste;
	t_list	*bloc;

	if (!lst || !f | !del)
		return (NULL);
	liste = 0;
	while (lst)
	{
		bloc = ft_lstnew(f(lst->content));
		if (!bloc)
		{
			ft_lstclear(&liste, del);
			return (NULL);
		}
		ft_lstadd_back(&liste, bloc);
		lst = lst->next;
	}
	return (liste);
}
