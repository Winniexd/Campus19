/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micropaint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:58:45 by matias            #+#    #+#             */
/*   Updated: 2024/05/17 13:42:12 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micropaint.h"

int write_error(char *str)
{
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
    return 1;
}

int check_in_r(t_rect *r, float x, float y)
{
    return 0;
}

void get_pxl(t_rect *r, t_mpaint *p, int x, int y)
{
        int in_r;
        
        in_r = check_in_r(r, (float)x, (float)y);
}

int get_rect(FILE *stream, t_mpaint *p)
{
    int ret;
    t_rect *r;

    r = malloc(sizeof(t_rect));
    if (!r)
        return 1;
    ret = fscanf(stream, "%c %f %f %f %f %c\n", &r->type, &r->x, &r->y, &r->width, &r->height, &r->c);
    while (ret == 6)
    {
        if (r->x <= 0.00000000 || r->y < 0.00000000 || (r->type != 'r' && r->type != 'R'))
            return free(r), 1;
        for (int x = 0; x < p->width; x++)
            for (int y = 0; y < p->height; y++)
                get_pxl(r, p, x, y);
        ret = fscanf(stream, "%c %f %f %f %f %c\n", &r->type, &r->x, &r->y, &r->width, &r->height, &r->c);
    }
    free(r);
    return 0;
}

int parse_data(FILE *stream, t_mpaint *p)
{
    int ret;
    
    ret = fscanf(stream, "%d %d %c\n", &p->width, &p->height, &p->bg_c);
    if (ret == 3)
    {
        if (p->width < 1 || p->width > 300 || p->height < 1 || p->height > 300)
            return 1;
        p->grid = malloc(p->width * p->height);
        if (!p->grid)
            return 1;
        memset(p->grid, p->bg_c, p->width * p->height);
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    FILE *stream;
    t_mpaint *p;
    if (argc != 2)
        return write_error("Error: arguments");
    p = malloc(sizeof(t_mpaint));
    stream = fopen(argv[1], "r");
    if (!stream || parse_data(stream, p) || get_rect(stream, p))
        return write_error("Error: Operation file corrupted");
        
    for (int i = 0; i < p->height * p->width; i++)
    {
        write(1, &p->grid[i], 1);
        if (!((i + 1) % p->width) && i > 0)
            write(1, "\n", 1);
    }
    fclose(stream);
    free(p);
    return 0;
}