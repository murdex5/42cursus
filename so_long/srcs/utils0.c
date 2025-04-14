/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:38:46 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/09 13:38:48 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file_type(char *str)
{
	char	**str2;
	int		i;
	char	*temp;

	str2 = ft_split(str, '.');
	if (!str2)
		return (err_msg_std("Ft_split faield"), 0);
	i = 0;
	while (str2[i])
		i++;
	temp = ft_strdup(str2[i - 1]);
	if (!temp)
		return (err_msg_std("Memory allocation failed for temo"), 0);
	if (ft_strncmp(temp, "ber", ft_strlen("ber")) == 0)
		return (free_n_returnt(str2, temp, NULL), 1);
	return (free_n_returnt(str2, temp, "This type of file is not supported!"),
		0);
}

char	*int_to_str(int len, int num)
{
	char *str;
	int temp;

	len = 0;
	temp = len;
	if (temp == 0)
		len = 1;
	else
	{
		while (temp != 0)
		{
			len++;
			temp /= 10;
		}
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
