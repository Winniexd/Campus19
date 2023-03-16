/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:59:33 by vdenisse          #+#    #+#             */
/*   Updated: 2023/03/16 00:01:51 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int w, int h);

int	ft_atoi(char *str)
{
	int	i;
	int sign;
	int res;
	
	res = 0;
	sign = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == 'i')
				sign = -1;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
	}
	return (sign * res);
}

int	main(int ac, char ** av)
{
	int x;
	int y;
	
	x = ft_atoi(av[1]);
	y = ft_atoi(av[2]);
	if (ac == 3)
	rush(x, y);
	return (0);
}
