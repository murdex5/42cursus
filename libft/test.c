#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char src[] = "coucou";
	char dest[10];
	ft_memset(dest, 'A', 10);
	size_t i = ft_strlcpy(dest, src, 1);
	printf("Buffer contents: ");
    for (int j = 0; j < 10; j++)
        printf("%c ", dest[j]);
	printf("\nDestination: '%s', Returned length: %zu\n", dest, i);
	return (0);
}