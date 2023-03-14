#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str);

int main()
{
    char *str1 = "123";
    char *str2 = "-456";
    char *str3 = "    789";
    char *str4 = "0";
    char *str5 = "\n  \t--42";
    char *str6 = "2147483647";
    char *str7 = "-2147483648";
    char *str8 = "2147483648"; // out of range for int
    char *str9 = "-2147483649"; // out of range for int

    int res1 = ft_atoi(str1);
    int res2 = ft_atoi(str2);
    int res3 = ft_atoi(str3);
    int res4 = ft_atoi(str4);
    int res5 = ft_atoi(str5);
    int res6 = ft_atoi(str6);
    int res7 = ft_atoi(str7);
    int res8 = ft_atoi(str8);
    int res9 = ft_atoi(str9);

    printf("Testing ft_atoi:\n");
    printf("ft_atoi(\"%s\") = %d\n", str1, res1);
    printf("ft_atoi(\"%s\") = %d\n", str2, res2);
    printf("ft_atoi(\"%s\") = %d\n", str3, res3);
    printf("ft_atoi(\"%s\") = %d\n", str4, res4);
    printf("ft_atoi(\"%s\") = %d\n", str5, res5);
    printf("ft_atoi(\"%s\") = %d\n", str6, res6);
    printf("ft_atoi(\"%s\") = %d\n", str7, res7);
    printf("ft_atoi(\"%s\") = %d\n", str8, res8);
    printf("ft_atoi(\"%s\") = %d\n", str9, res9);

    int std_res1 = atoi(str1);
    int std_res2 = atoi(str2);
    int std_res3 = atoi(str3);
    int std_res4 = atoi(str4);
    int std_res5 = atoi(str5);
    int std_res6 = atoi(str6);
    int std_res7 = atoi(str7);
    int std_res8 = atoi(str8);
    int std_res9 = atoi(str9);

    printf("\nTesting atoi:\n");
    printf("atoi(\"%s\") = %d\n", str1, std_res1);
    printf("atoi(\"%s\") = %d\n", str2, std_res2);
    printf("atoi(\"%s\") = %d\n", str3, std_res3);
    printf("atoi(\"%s\") = %d\n", str4, std_res4);
    printf("atoi(\"%s\") = %d\n", str5, std_res5);
    printf("atoi(\"%s\") = %d\n", str6, std_res6);
    printf("atoi(\"%s\") = %d\n", str7, std_res7);
    printf("atoi(\"%s\") = %d\n", str8, std_res8);
    printf("atoi(\"%s\") = %d\n", str9, std_res9);

    return 0;
}

