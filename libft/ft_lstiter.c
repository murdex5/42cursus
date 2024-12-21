/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:22:29 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/21 21:22:30 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list **lst, void (*f)(void *))
{
	t_list *temp;

	if (!lst || !f)
		return ;
	temp = *lst;
	while (temp->next != '\0')
	{
		(*f)(temp->content);
		temp = temp->next;
	}
}