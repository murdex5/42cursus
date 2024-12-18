#include "libft.h"
#include <stdio.h>


int	main(void)
{
	char *s = ft_substr("tripouille", 1, 1);
	printf("%s \n", s);
	free(s);
	return (0);
}