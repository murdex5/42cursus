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
# include <limits.h>
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
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int						error_msg(void);
void					current_index(t_stack_node *node);
void					free_node(t_stack_node *node);
void					*ft_realloc(void *a, size_t new_size);
t_stack_node			*init_node(void);
int						int_arr_len(int *arr);
int						check_numbers(char *c);
t_stack_node			*checks(char **numbers);
t_stack_node			*build_list(t_stack_node *node);
int						get_items(char const *s, char c);
char					**get_ints(int argc, char **argv, int *len);
int						get_len_except(char *num);
t_stack_node			*get_node(char *num);
t_stack_node			*get_first_node(t_stack_node *node);
void					free_node_list(t_stack_node *node);
void					free_unbuilt_list(t_stack_node *node);
void					free_str_list(char **str);
t_stack_node			*create_list(char **numbers);
t_stack_node			*get_last_node(t_stack_node *node);
void					set_indexes(t_stack_node *node);
void					set_target_node_a(t_stack_node *stack_a,
							t_stack_node *stack_b);
void					set_cheapest(t_stack_node *stack);
int						pa(t_stack_node **stack_a, t_stack_node **stack_b);
int						pb(t_stack_node **stack_a, t_stack_node **stack_b);
int						sa(t_stack_node **stack_a, bool to_print);
int						sb(t_stack_node **stack_b, bool to_print);
int						ss(t_stack_node **stack_a, t_stack_node **stack_b);
int						ra(t_stack_node **stack_a, bool to_print);
int						rb(t_stack_node **stack_b, bool to_print);
int						rr(t_stack_node **stack_a, t_stack_node **stack_b);
int						rra(t_stack_node **stack_a, bool to_print);
int						rrb(t_stack_node **stack_b, bool to_print);
int						rrr(t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node			*get_max_node_from(t_stack_node *node);
t_stack_node			*get_min_node_from(t_stack_node *node);
t_stack_node			*get_cheapest_from(t_stack_node *node);
void					move_a_to_b(t_stack_node **stack_a,
							t_stack_node **stack_b);
int						count_stack(t_stack_node *node);
bool					stack_sorted(t_stack_node *node);
int						sort_three(t_stack_node **stack_a);
int						sort_stack(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					init_nodes(t_stack_node *stack_a,
							t_stack_node *stack_b);
void					init_nodes_b(t_stack_node *stack_a,
							t_stack_node *stack_b);
void					rotate_both_stacks(t_stack_node **stack_a,
							t_stack_node **stack_b,
							t_stack_node *cheapest_node);
void					rev_rotate_both_stacks(t_stack_node **stack_a,
							t_stack_node **stack_b,
							t_stack_node *cheapest_node);
void					prep_stacks(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					move_a_to_b(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					move_b_to_a(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					min_to_top(t_stack_node **stack);
#endif
