#include <stdio.h>

int     ft_is_prime(int nb);
int     ft_find_next_prime(int nb);

int     main(void)
{
        int     nb;
        int     next_prime;

        nb = 0;
        while (nb < 100)
        {
                next_prime = ft_find_next_prime(nb);
                printf("Next prime after %d is %d\n", nb, next_prime);
                nb = next_prime + 1;
        }
        return (0);
}

