/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:34:55 by mdreesen          #+#    #+#             */
/*   Updated: 2023/06/01 11:34:56 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

typedef struct s_command
{
    char *command;
    char **path;
    char *args[100];
    int f;
}   t_command;

void    pipex(int file1, int file2, char **argv, char **envp);
void    command_init(int file, t_command *command);

#endif