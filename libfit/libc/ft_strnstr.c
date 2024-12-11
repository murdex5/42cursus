/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:54:27 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 13:11:39 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little == NULL)
		return ((char *)big);
	while (((unsigned char *)big)[i] != '\0')
	{
		if (((unsigned char *)big)[i] == ((unsigned char *)little)[0])
		{
			j = 0;
			while (((unsigned char *)big)[i] == ((unsigned char *)little)[j]
				&& j < len)
			{
				i++;
				j++;
			}
			if (j == len)
				return ((char *)little);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str;
	char	*little;
	size_t	len;
	char	*result;

	str = "Hello how are you world guys!";
	little = "world";
	len = (size_t)strlen(little);
	result = ft_strnstr(str, little, len);
	printf("%s \n", result);
	return (0);
}
*/