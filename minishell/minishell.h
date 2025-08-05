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

typedef enum e_redirect_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}						t_redirect_type;

typedef enum e_tokentype
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC,
	TOKEN_EOF,
}						t_tokentype;

typedef enum e_node_type
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_SUBSHELL
}						t_node_type;

typedef struct			s_ast_node;

typedef struct s_redirect
{
	t_redirect_type		type;
	char				*filename;
	struct s_redirect	*next;
}						t_redirect;

typedef struct s_ast_node
{
	t_node_type			type;
}						t_ast_node;

typedef struct s_command_node
{
	t_node_type			type;
	char				**argv;
	t_redirect			*redirections;
}						t_command_type;

typdef struct s_subshell_node
{
	t_node_type type;
	struct s_ast_node *child;
	t_redirect *redirections;
}						t_subshell_node;

typedef struct s_token
{
	char				*value;
	t_tokentype			type;
	struct s_token		*next;
}						t_token;

char					**convert_list_to_argv(t_list *words);
void					report_syntax_error(char *msg, t_token *token);
int						is_redirection(t_token *token);
char					**create_list(t_token *token);
int						list_len(t_token *token);
int						word_len(t_token *token);
void					std_err_msg(char *msg);
t_token					*init_tokens(char *line);
t_token					*get_tokens(char **tokens);
void					specify_tokens(t_token *token);
int						get_array_len(char **tokens);
int						is_separator(char c);
int						count_words_shell(const char *s);
char					*get_next_word(const char **s);
int						free_on_error(char **result, int word_count);
void					free_tokens(char **tokens);
char					**construct_tokens(char *line);
void					free_on_exiting_list(t_token *tokens);
void					free_r1(char *r1);
void					ft_exit(char *r1, t_token *token);
void					*ft_realloc(void *a, size_t old_size, size_t new_size);
void					signal_handler(int sig);
int						process_signals(struct sigaction *sa);
#endif
