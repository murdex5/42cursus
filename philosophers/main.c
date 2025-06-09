/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:01:13 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/09 12:01:35 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine (void *data_pointer)
{
	int dead = 9;

	while (dead < 1)
	{
		/*do something herer*/
	}
	return (data_pointer);
}

int	main(int argc, char **argv)
{
	int	nums[argc - 1];
	t_data *data;

	if (!checks(nums, argc, argv))
		return (1);
	if (!check_num_values(nums))
		return (1);
	data = init(nums);
	if (!data)
		return (1);
	if (data)
		free_data_struct(data);
	return (0);
}

