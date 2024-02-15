/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:33:33 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/15 13:37:40 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

#include "../minishell.h"

void    cd(char *path);
void	echo(char *str);
void	pwd(char *path);
void	export();
void	unset();
void	env();
void	exit();

#endif