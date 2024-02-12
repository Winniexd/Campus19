/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:29:23 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/12 11:03:54 by mdreesen         ###   ########.fr       */
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
	int				times_ate;
	long long		last_meal;
	pthread_t		thread_id;
	struct s_data	*data;
}					t_philosopher;

typedef struct s_data
{
	int				philo_count;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				to_eat;
	int				died;
	long long		start_time;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	writing;
	t_philosopher	philos[250];
}					t_data;

int					init_philosophers(char **argv, t_data *data);
int					run_simulation(t_data *data);
int					ft_atoi(const char *str);
int					check_args(char **argv);
long long			timestamp(void);
void				philo_sleep(t_philosopher *philo);
void				philo_print(t_data *data, int philo_id, char *action);
void				print_action(t_philosopher *philo, char *action);
void				safe_exit(t_data *data);

#endif