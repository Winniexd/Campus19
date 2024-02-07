/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:20:32 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/07 14:38:03 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	run_simulation(t_data *data)
{
	int				i;
	t_philosopher	*philosopher;

	i = 0;
	data->start_time = timestamp();
	/*
	while (i++ < data->philo_count)
	{
		pthread_create(&(philosopher[i].thread_id), NULL,
				routine function, &philosopher[i]);
	}
    */
   return (1);
}
