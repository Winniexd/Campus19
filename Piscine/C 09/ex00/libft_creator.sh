#!/bin/bash

gcc -c -o ft_putchar.o ft_putchar.c
gcc -c -o ft_swap.o ft_swap.c
gcc -c -o ft_putstr.o ft_putstr.c
gcc -c -o ft_strlen.o ft_strlen.c
gcc -c -o ft_strcmp.o ft_strcmp.c

ar rcs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

rm *.o
