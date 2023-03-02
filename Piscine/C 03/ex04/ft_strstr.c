/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:14:31 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/02 11:20:35 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	to_find_len;

	i = 0;
	j = 0;
	to_find_len = 0;
	while (to_find[to_find_len])
		to_find_len++;
	if (to_find_len == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return ((void *)0);
}
