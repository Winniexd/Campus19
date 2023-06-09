/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:50:40 by mdreesen          #+#    #+#             */
/*   Updated: 2023/06/01 11:50:41 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char* custom_getenv(const char *name, char **envp) {
    int i;
    char *equals;
    int namelen;

    i = 0;
    while (envp[i] != NULL)
    {
        equals = strchr(envp[i], '=');
        if (equals != NULL)
        {
            namelen = equals - envp[i];
            if (strncmp(envp[i], name, namelen) == 0)
                return equals + 1;
        }
        i++;
    }
    return NULL;
}

char *find_path(char *cmd, char **envp)
{
    char *path;
    char **path_split;
    char *path_cmd;
    int i;

    path = custom_getenv("PATH", envp);
    path_split = ft_split(path, ':');
    i = 0;
    while (path_split[i] != NULL)
    {
        path_cmd = ft_strjoin(path_split[i], "/");
        path_cmd = ft_strjoin(path_cmd, cmd);
        if (access(path_cmd, F_OK) == 0)
            return path_cmd;
        i++;
    }
    return NULL;   
}