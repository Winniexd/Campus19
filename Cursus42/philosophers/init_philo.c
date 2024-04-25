/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:32:40 by mdreesen          #+#    #+#             */
/*   Updated: 2024/04/25 12:23:02 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->philo_count)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (0);
	}
	if (pthread_mutex_init(&(data->writing), NULL))
		return (0);
	if (pthread_mutex_init(&(data->eating), NULL))
		return (0);
	return (1);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left_fork_id = i;
		data->philos[i].right_fork_id = (i + 1) % data->philo_count;
		data->philos[i].data = data;
		i++;
	}
}

int	init_philosophers(char **argv, t_data *data)
{
	data->philo_count = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->to_eat = ft_atoi(argv[5]);
	data->died = 0;
	if (!init_mutex(data))
		return (0);
	init_philos(data);
	return (1);
}
