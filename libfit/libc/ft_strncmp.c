/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:02:58 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 11:12:21 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char	*str = "HELLO";
	char	*s = "Apple";
	printf("%d \n", ft_strncmp(str, s, 5));
	return (0);
}*/
