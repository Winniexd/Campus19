/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 08:52:29 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/02 11:23:48 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (*s1 == *s2 && *s1 && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
