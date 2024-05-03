/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:20:32 by mdreesen          #+#    #+#             */
/*   Updated: 2024/05/03 11:20:01 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	monitor_deaths(t_data *data)
{
	int	i;

	while (!(data->died))
	{
		i = 0;
		while (i < data->philo_count && !(data->died))
		{
			pthread_mutex_lock(&(data->eating));
			if (timestamp() - data->philos[i].last_meal > data->time_die)
			{
				data->died = 1;
				print_action(&(data->philos[i]), "died");
			}
			pthread_mutex_unlock(&(data->eating));
			usleep(100);
			i++;
		}
		i = 0;
		while (data->to_eat > 0 && data->philos[i].times_ate == data->to_eat)
			i++;
		if (data->to_eat > 0 && i == data->philo_count)
			break ;
	}
}

void	philo_sleep(t_philosopher *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->data->time_sleep * 1000);
}

void	philo_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->data->forks[philo->left_fork_id]));
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->data->forks[philo->right_fork_id]));
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->data->eating));
	print_action(philo, "is eating");
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&(philo->data->eating));
	usleep(philo->data->time_eat * 1000);
	philo->times_ate++;
	pthread_mutex_unlock(&(philo->data->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(philo->data->forks[philo->right_fork_id]));
}

void	*philo_routine(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	if (philo->id % 2)
		usleep(10000);
	while (!(philo->data->died))
	{
		philo_eat(philo);
		if (philo->data->to_eat > 0 && philo->data->to_eat == philo->times_ate)
			break ;
		philo_sleep(philo);
		print_action(philo, "is thinking");
	}
	return (NULL);
}

int	run_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = timestamp();
	while (i < data->philo_count)
	{
		pthread_create(&(data->philos[i].thread_id), NULL, &philo_routine,
			&(data->philos[i]));
		data->philos[i].last_meal = timestamp();
		i++;
	}
	monitor_deaths(data);
	safe_exit(data);
	return (1);
}
