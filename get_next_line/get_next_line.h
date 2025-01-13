/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:08:02 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/13 16:08:04 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*buff;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
int					find_newline(t_list *list);
t_list				*find_last_node(t_list *list);
size_t				get_len_lists(t_list *list);
void				copy_str(t_list *list, char *str);
void				append(char **list, char *buf);
void				dealloc(t_list **list, t_list *node, char *buf);
#endif