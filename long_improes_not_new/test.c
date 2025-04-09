#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	last_chars(char *str, char *type)
{
	char	*dot;
	int		i;
	int		j;

	dot = malloc(sizeof(char) * 5);
	if (!dot)
		return (0);
	i = (int)strlen(str) - 5;
	j = -1;
	while (str[i] != '\0')
	{
		dot[++j] = str[++i];
	}
	dot[j] == '\0';
	if (strncmp(dot, type, strlen(type)) == 0)
		return (1);
	else
		return (0);
}

int	main(void)
{
	char *str = "./map.ber";
	int i = last_chars(str, ".ber");
	printf("%d\n", i);
	return (0);
}