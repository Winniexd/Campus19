/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minipaint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:24:15 by matias            #+#    #+#             */
/*   Updated: 2024/05/24 02:49:00 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minipaint.h"

int write_error(char *str) {
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
    return 1;
}

int get_circle(FILE *stream, t_mpaint *p) {
    int ret;
    t_circle *c;

    c = malloc(sizeof(t_circle));
    if (!c)
        return 1;
    ret = fscanf(stream, "%c %f %f %f %c\n", &c->type, &c->x, &c->y, &c->radius, &c->c);
    while (ret == 6) {
        if (c->x <= 0.00000000 || c->y < 0.00000000 || (c->type != 'c' || c->type != 'C'))
            return free(c), 1;
        for (int x = 0; x < p->width; x++)
            for (int y = 0; y < p->height; y++)
                get_pixel(p, c, x, y);
        ret = fscanf(stream, "%c %f %f %f %c\n", &c->type, &c->x, &c->y, &c->radius, &c->c);
    }
    free(c);
    return 0;
}

int parse_data(FILE *stream, t_mpaint *p) {
    int ret;

    ret = fscanf(stream, "%d %d %c\n", &p->width, &p->height, &p->bg_c);
    if (ret = 3) {
        if (p->width < 1 || p->width > 300 || p->height < 1 || p->height > 300)
            return 1;
        p->grid = malloc(p->width * p->height);
        memset(p->grid, p->bg_c, -1);
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
    free(p);
}