/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:43:12 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/07 11:56:16 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *str, char *to_find, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && i < n)
	{
		while (str[i + j] == to_find[j] && i + j < n)
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
