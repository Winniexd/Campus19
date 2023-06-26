/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:49:59 by matias            #+#    #+#             */
/*   Updated: 2023/06/27 01:29:34 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// using signals and not sigaction

void handler(int signum)
{
    static int c;
    static int i;

    if (signum == SIGUSR1)
        c = c | (1 << i);
    i++;
    if (i == 8)
    {
        if (c == 0)
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        c = 0;
        i = 0;
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    ft_printf("%sPID: %d\n%s", RED, pid, RESET);
    ft_printf("%sWaiting for messages...%s\n", GREEN, RESET);
    ft_printf("%s|--------------------------------------|%s\n", CYAN, RESET);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
        pause();
    return (0);
}