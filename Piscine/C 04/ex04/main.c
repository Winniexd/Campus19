#include <stdio.h>

void ft_putnbr_base(int nbr, char *base);

int main() {
    int decimal = 255;

    printf("Decimal: %d\n", decimal);
    printf("Binary: ");
    ft_putnbr_base(decimal, "01");
    printf("\n");
    printf("Octal: ");
    ft_putnbr_base(decimal, "poneyvif");
    printf("\n");
    printf("Hexadecimal: ");
    ft_putnbr_base(decimal, "0123456789ABCDEF");
    printf("\n");

    return 0;
}

