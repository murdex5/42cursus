/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:06:46 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/25 11:06:47 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// Forward declarations for static functions
static int	exec_ast(t_ast_node *node, char **envp);
static int	exec_pipe_node(t_pipe_node *pipe_node, char **envp);
static int	exec_simple_command(t_command_node *cmd, char **envp);
static void	handle_redirections(t_redirect *redir_list);
static char	*resolve_command_path(const char *cmd_name, char **envp);
char		**get_path(char *env[]);

int	execute_ast_pipeline(t_ast_node *node, char **envp)
{
	if (!node)
		return (0);
	return (exec_ast(node, envp));
}

static int exec_ast(t_ast_node *node, char **envp)
{
	if (node->type == NODE_COMMAND)
		return (exec_simple_command((t_command_node *)node, envp));
	if (node->type == NODE_PIPE)
		return (exec_pipe_node((t_pipe_node *)node, envp));
	// if (node->type == NODE_SUBSHELL)
	// 	return (exec_subshell_node((t_subshell_node *)node, envp));
	fprintf(stderr, "minishell: Unrecognized node type %d\n", node->type);
	return (127);
}

static int	exec_simple_command(t_command_node *cmd, char **envp)
{
	pid_t	pid;
	int		status;
	char	*cmd_path;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		handle_redirections(cmd->redirections);
		cmd_path = resolve_command_path(cmd->argv[0], envp);
		if (!cmd_path)
		{
			fprintf(stderr, "minishell: %s: command not found\n", cmd->argv[0]);
			exit(127);
		}
		execve(cmd_path, cmd->argv, envp);
		fprintf(stderr, "minishell: %s: %s\n", cmd->argv[0], strerror(errno));
		free(cmd_path);
		exit(126);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (128 + WTERMSIG(status));
}

static int	exec_pipe_node(t_pipe_node *pipe_node, char **envp)
{
	int		fd[2];
	pid_t	pid_left;
	pid_t	pid_right;
	int		status_right;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid_left = fork();
	if (pid_left == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid_left == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exit(exec_ast(pipe_node->left, envp));
	}
	pid_right = fork();
	if (pid_right == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid_right == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		exit(exec_ast(pipe_node->right, envp));
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_left, NULL, 0);
	waitpid(pid_right, &status_right, 0);
	if (WIFEXITED(status_right))
		return (WEXITSTATUS(status_right));
	return (128 + WTERMSIG(status_right));
}

static void	handle_redirections(t_redirect *redir_list)
{
	t_redirect	*curr;
	int			fd;

	curr = redir_list;
	while (curr)
	{
		if (curr->type == REDIR_OUT)
			fd = open(curr->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (curr->type == REDIR_IN)
			fd = open(curr->filename, O_RDONLY);
		else if (curr->type == REDIR_APPEND)
			fd = open(curr->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = -1; // Placeholder for HEREDOC or other types
		if (fd == -1)
		{
			perror(curr->filename);
			exit(1);
		}
		if (curr->type == REDIR_IN)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close(fd);
		curr = curr->next;
	}
}

static void	free_paths(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

static char	*resolve_command_path(const char *cmd_name, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*tmp;
	int		i;

	if (!cmd_name || !*cmd_name)
		return (NULL);
	if (ft_strchr(cmd_name, '/'))
	{
		if (access(cmd_name, X_OK) == 0)
			return (ft_strdup(cmd_name));
		return (NULL);
	}
	paths = get_path(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd_name);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			free_paths(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

char	**get_path(char *env[])
{
	char **paths;
	char *path_env;

	path_env = NULL;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path_env = *env;
			break ;
		}
		env++;
	}
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env + 5, ':');
	return (paths);
}