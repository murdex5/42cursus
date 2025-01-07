#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	count_first_param(char *str)
{
	int	count;
	int	len;

	len = (int)ft_strlen(str);
	count = 0;
	while (str[count] != '\0' && str[count + 1] != '\0')
	{
		if (str[count] == '%' && (str[count + 1] == 'c' || str[count + 1] == 's'
				|| str[count + 1] == 'd' || str[count + 1] == 'p' || str[count
				+ 1] == 'i' || str[count + 1] == 'u' || str[count + 1] == '%'
				|| str[count + 1] == 'x' || str[count + 1] == 'X'))
		{
			if (len != 0)
				len -= 2;
		}
		count++;
	}
	return (len);
}

int	main(void)
{
	char *str = "Hello%s %p";
	int count = count_first_param(str);
	printf("%d\n", count);
	return (0);
}