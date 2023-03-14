/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:19:44 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/13 12:19:49 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_itoa_base(int nbr, char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	j;
	int	result;
	int	base_len;

	i = 0;
	result = 0;
	base_len = ft_strlen(base);
	while (nbr[i])
	{
		j = 0;
		while (base[j])
		{
			if (nbr[i] == base[j])
			{
				result = result * base_len + j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		result;
	char	*str;
	int		len;
	int		base_to_len;

	result = ft_atoi_base(nbr, base_from);
	len = ft_itoa_base(result, base_to);
	base_to_len = ft_strlen(base_to);
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (result > 0)
	{
		str[i] = base_to[result % base_to_len];
		result /= base_to_len;
		i++;
	}
	if (i == 0)
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}
