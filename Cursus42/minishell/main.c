/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:07:19 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/15 13:15:13 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    pid_t p = fork();
    if (p == 0)
        printf("Child PID = %d\n", getpid());
    else
        printf("Parent has PID = %d, Child PID = %d\n", getpid(), p);
    return (0);
}