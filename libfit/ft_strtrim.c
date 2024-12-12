/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:57:39 by malshapraboth     #+#    #+#             */
/*   Updated: 2024/12/12 18:57:41 by malshapraboth    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isin(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static void	check_len(char const *s1, char const *set, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (isin(s1[i], set))
		{
			len--;
		}
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	trim_len;
	size_t	i;
	size_t	j;

	j = 0;
	trim_len = ft_strlen(s1);
	check_len(s1, set, trim_len);
	result = malloc(sizeof(char) * trim_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		if (!isin(s1[i], set))
		{
			result[j] = s1[i];
			j++;
		}
		i++;
	}
	return (result);
}
/*
int	main(void)
{
	char *str = "Hello, World!";
	char *charset = ", !l";
	char *modstr = ft_strtrim(str, charset);
	printf("%s\n", modstr);
	return (0);
}*/
