/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:05:40 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/17 10:23:13 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		error_msg(void);
int		free_list(int **a, int len);
void	*ft_realloc(void *a, size_t new_size);
int		int_arr_len(int *arr);
int		check_numbers(char *c);
int		**checks(int argc, char **argv, int *len);
int		get_items(char const *s, char c);
int		**get_ints(int argc, char **argv, int *len);
#endif
