/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:50:18 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/15 10:50:21 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
int					find_newline(t_list *list);
void				append(t_list **list, char *buffer);
t_list				*find_last_node(t_list *list);
int					list_str_len(t_list *list);
void				copy_str(t_list *list, char *buffer);
void				polish_list(t_list **list);
void				dealloc(t_list *list);
#endif