/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:32:47 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/12 17:32:50 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef enum e_tokentype
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC,
	TOKEN_EOF,
}					t_tokentype;

typedef struct s_token
{
	char			*value;
	t_tokentype		type;
	struct s_token	*next;
}					t_token;

t_token	*init_tokens(char *line);
t_token				*get_tokens(char **tokens);
void				specify_tokens(t_token *token);
int					get_array_len(char **tokens);
int					is_separator(char c);
int					count_words_shell(const char *s);
char				*get_next_word(const char **s);
int					free_on_error(char **result, int word_count);
void				free_tokens(char **tokens);
char				**construct_tokens(char *line);
void				free_on_exiting_list(t_token *tokens);
void				free_r1(char *r1);
void				ft_exit(char *r1, t_token *token);
void				*ft_realloc(void *a, size_t old_size, size_t new_size);
void				signal_handler(int sig);
int					process_signals(struct sigaction *sa);
#endif
