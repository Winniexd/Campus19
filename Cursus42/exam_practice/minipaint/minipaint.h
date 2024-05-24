/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minipaint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:18:25 by matias            #+#    #+#             */
/*   Updated: 2024/05/24 02:37:49 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPAINT_H
#define MINIPAINT_H

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_mpaint {
    int width;
    int height;
    char bg_c;
    char *grid;
}   t_mpaint;

typedef struct s_circle {
    float radius;
    float x;
    float y;
    char c;
    char type;
}   t_circle;

#endif