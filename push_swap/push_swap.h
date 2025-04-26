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
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_medium;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int						error_msg(void);
int						free_list(int **a, int len);
void					free_node(t_stack_node *node);
void					*ft_realloc(void *a, size_t new_size);
t_stack_node			*init_node(void);
int						int_arr_len(int *arr);
int						check_numbers(char *c);
t_stack_node			*checks(int argc, char **argv, int *len);
t_stack_node			*build_list(t_stack_node *node);
int						get_items(char const *s, char c);
int						**get_ints(int argc, char **argv, int *len);
t_stack_node			*get_node(char **argv, int i, t_stack_node *prev);
t_stack_node			*get_first_node(t_stack_node *node);
void					free_node_list(t_stack_node *node);
void					free_unbuilt_list(t_stack_node *node);
t_stack_node			*create_list(int argc, char **argv, int *len);
t_stack_node			*get_last_node(t_stack_node *node);
int						pa(t_stack_node **stack_a, t_stack_node **stack_b);
int						pb(t_stack_node **stack_a, t_stack_node **stack_b);
int						sa(t_stack_node **stack_a);
int						sb(t_stack_node **stack_b);
int						ss(t_stack_node **stack_a, t_stack_node **stack_b);
int						ra(t_stack_node **stack_a);
int						rb(t_stack_node **stack_b);
int						rr(t_stack_node **stack_a, t_stack_node **stack_b);
int						rra(t_stack_node **stack_a);
int						rrb(t_stack_node **stack_b);
int						rrr(t_stack_node **stack_a, t_stack_node **stack_b);
#endif
