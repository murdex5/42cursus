/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:28 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 15:45:31 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	char	*str;
	size_t	i;
	char	*sub;

	str = (char *)s;
	if (!s)
		return (NULL);
	sub_len = strlen(&s[start]);
	sub = malloc(sizeof(char) * sub_len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (str[start] != '\0' && i < len)
	{
		sub[i++] = str[start++];
	}
	sub[i] = '\0';
	return (sub);
}

/*
int	main(void)
{
	char    *main = "Hello, World!";
	char    *test = ft_substr(main, 7, strlen(main));
	printf("%s\n", test);
	free(test);
	return (0);
}*/