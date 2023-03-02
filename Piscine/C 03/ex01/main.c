#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, int n);

int main(void)
{
    const char* s1[] = {"", "abc", "abc", "abc", "abc", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef"};
    const char* s2[] = {"", "abcd", "ab", "abd", "abcd", "abc", "abc", "abcdef", "abcde", "abcdefg"};
    int n[] = {0, 3, 3, 4, 0, 3, 6, 9, 5, 10};
    int expected[] = {0, 0, 'a' - 'b', 'a' - 'a', 0, 0, 0, 0, 'a' - 'e', 'a' - 'a'};

    int num_tests = sizeof(s1) / sizeof(s1[0]);

    printf("Testing ft_strncmp against strncmp:\n\n");

    for (int i = 0; i < num_tests; i++)
    {
        printf("Test %d:\n", i + 1);
        printf("s1: \"%s\"\n", s1[i]);
        printf("s2: \"%s\"\n", s2[i]);
        printf("n: %d\n", n[i]);

        int res_ft = ft_strncmp(s1[i], s2[i], n[i]);
        int res_strncmp = strncmp(s1[i], s2[i], n[i]);

        printf("ft_strncmp result: %d\n", res_ft);
        printf("strncmp result: %d\n", res_strncmp);
        printf("Expected result: %d\n", expected[i]);
        printf("Results match? %s\n", res_ft == expected[i] && res_ft == res_strncmp ? "Yes" : "No");

        printf("\n");
    }

    return 0;
}

