/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minipaint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:24:15 by matias            #+#    #+#             */
/*   Updated: 2024/05/24 12:55:30 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minipaint.h"

int write_error(char *str) {
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
    return 1;
}

float ft_powf(float a) {
    return a * a;
}

float dist(float cx, float cy, float x, float y) {
    return (ft_powf(x - cx) + ft_powf(y - cy));        
}

int is_in_circle(t_mpaint *p, t_circle *c, float x, float y) {
    float distance = sqrtf(dist(c->x, c->y, x, y));
    distance = distance - c->radius;
    if (distance <= 0.00000000) {
        if (distance <= -1.00000000)
            return 1;
        return 2;
    }
    return 0;
}

void get_pixel(t_mpaint *p, t_circle *c, int x, int y) {
    int is_in = is_in_circle(p, c, (float)x, (float)y);
    
    if (is_in == 2 || (is_in == 1 && c->type == 'C'))
        p->grid[x + y * p->width] = c->c;
}

int get_circle(FILE *stream, t_mpaint *p) {
    int ret;
    t_circle *c;

    c = malloc(sizeof(t_circle));
    if (!c)
        return 1;
    ret = fscanf(stream, "%c %f %f %f %c\n", &c->type, &c->x, &c->y, &c->radius, &c->c);
    while (ret == 5) {
        if (c->x <= 0.00000000 || c->y < 0.00000000 || (c->type != 'c' && c->type != 'C'))
            return free(c), 1;
        for (int x = 0; x < p->width; x++)
            for (int y = 0; y < p->height; y++)
                get_pixel(p, c, x, y);
        ret = fscanf(stream, "%c %f %f %f %c\n", &c->type, &c->x, &c->y, &c->radius, &c->c);
    }
    if (ret == -1)
        return free(c), 0;
    free(c);
    return 1;
}

int parse_data(FILE *stream, t_mpaint *p) {
    int ret;

    ret = fscanf(stream, "%d %d %c\n", &p->width, &p->height, &p->bg_c);
    if (ret = 3) {
        if (p->width < 1 || p->width > 300 || p->height < 1 || p->height > 300)
            return 1;
        p->grid = malloc(p->width * p->height);
        memset(p->grid, p->bg_c, p->width * p->height);
        return 0;
    }
    return 1;
}

int main(int argc, char **argv) {
    t_mpaint *p = malloc(sizeof(t_mpaint));
    if (argc != 2)
        return write_error("Error: argument");
    FILE *stream = fopen(argv[1], "r");
    if (!stream || parse_data(stream, p) || get_circle(stream, p))
        return write_error("Error: Operation file corrupted");
    for (int i = 0; i < p->width * p->height; i++) {
        write(1, &p->grid[i], 1);
        if (!((i + 1) % p->width) && i > 0)
            write(1, "\n", 1);
    }
    free(p);
}