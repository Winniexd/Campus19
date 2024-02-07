/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:43:48 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/07 14:37:27 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (2);
	if (!init_philosophers(argv, data))
		return (3);
	if (!run_simulation(data))
		printf("error");
	free(data);
	return (0);
}
