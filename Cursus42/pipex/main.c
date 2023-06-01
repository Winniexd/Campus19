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

int main(int argc, char **argv, char **envp)
{
    int file1;
    int file2;

    if (argc != 5)
        return (0);
    if (check_exist(argv[2]) || check_exist(argv[3]))
        return (-1);
    file1 = open(argv[1], O_RDONLY);
    file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (file1 < 0)
        ft_puterrno(strerror(errno), argv[1]);
    if (file2 < 0)
        ft_puterrno(strerror(errno), argv[4]);
    pipex(file1, file2, argv, envp);
    if (close(file1) < 0 || close(file2) < 0)
        return (ft_puterrno(strerror(errno), 0));
    return (0);
}