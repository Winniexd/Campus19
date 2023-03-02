#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	main(void)
{
	char	*tests[] = {
		"123",
		"-456",
		"+789",
		"0",
		"  42",
		" \t\n\r\v\f123",
		"99999999999999999999",
		"-99999999999999999999",
		"12345678901234567890",
		"-12345678901234567890",
		"2147483647",
		"-2147483648",
		"2147483648",
		"-2147483649",
		"",
		NULL
	};
	int	i;
	int	expected;
	int	actual;

	i = 0;
	while (tests[i])
	{
		expected = atoi(tests[i]);
		actual = ft_atoi(tests[i]);
		if (expected != actual)
		{
			printf("Test %d failed: expected=%d, actual=%d\n",
				i, expected, actual);
		}
		i++;
	}
	printf("Tests complete.\n");
	return (0);
}

