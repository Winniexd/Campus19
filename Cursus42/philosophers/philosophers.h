/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:29:23 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/07 14:32:17 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philosopher
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	pthread_t		thread_id;
}					t_philosopher;

typedef struct s_data
{
	int				philo_count;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				times_to_eat;
	long long		start_time;
	pthread_mutex_t	forks[250];
	t_philosopher	philosophers[250];
}					t_data;

int					init_philosophers(char **argv, t_data *data);
int					run_simulation(t_data *data);
int					ft_atoi(const char *str);
long long			timestamp(void);

#endif