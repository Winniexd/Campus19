/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:50:35 by mdreesen          #+#    #+#             */
/*   Updated: 2023/06/01 11:50:36 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    pipex(int file1, int file2, char **argv, char **envp)
{
    t_command command1;
    t_command command2;

    command_init(file1, &command1);
    command_init(file2, &command2);
}