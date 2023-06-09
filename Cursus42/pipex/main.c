/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:34:48 by mdreesen          #+#    #+#             */
/*   Updated: 2023/06/01 11:34:49 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exec_cmd(char *cmd, char **envp)
{
    char **cmd_split;
    char *path_cmd;

    cmd_split = ft_split(cmd, ' ');
    path_cmd = find_path(cmd_split[0], envp);
    if (path_cmd == NULL)
        exit(-1);
    if (execve(path_cmd, cmd_split, envp) == -1)
        exit(-1);
    free(path_cmd);
    free(cmd_split);
    exit(0);
}

void    child(int *end, char **argv, char **envp)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit(-1);
    dup2(end[0], 1);
    dup2(fd, 0);
    close(end[0]);
    exec_cmd(argv[2], envp);
}

void    parent(int *end, char **argv, char **envp)
{
    int fd;

    fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd == -1)
        exit(-1);
    dup2(end[1], 0);
    dup2(fd, 1);
    close(end[1]);
    exec_cmd(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
    int end[2];
    int pid;

    if (argc != 5)
        return (1);
    if (pipe(end) == -1)
        return (2);
    pid = fork();
    if (pid == -1)
        return (3);
    if (pid == 0)
        child(end, argv, envp);
    else
        parent(end, argv, envp);
    return (0);
}