/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micropaint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:59:21 by matias            #+#    #+#             */
/*   Updated: 2024/05/16 20:19:38 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROPAINT_H
#define MICROPAINT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct s_mpaint {
    char type;
    char bg_c;
    int width;
    int height;
    char *grid;
}   t_mpaint;

typedef struct s_rect {
    char type;
    float x;
    float y;
    float width;
    float height;
    char c;
} t_rect;

#endif