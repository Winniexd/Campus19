/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:07:08 by mdreesen          #+#    #+#             */
/*   Updated: 2024/04/03 10:59:35 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>
#include "libft/libft.h"
#include "builtins/builtins.h"

typedef struct s_env
{
    char    *value
    struct s_env *next;
}   t_env;
    

#endif