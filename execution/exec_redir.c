/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:28:50 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 08:40:23 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expand_herdoc(int fd_in, t_env *myenv)
{
	int		fd[2];
	char	*gnl;

	if (pipe(fd) == -1)
		return (perror("pipe"), exit(1), 0);
	gnl = expand_prime(get_next_line(fd_in), myenv);
	while (gnl)
	{
		write(fd[1], gnl, ft_strlen(gnl));
		gnl = expand_prime(get_next_line(fd_in), myenv);
	}
	(gnl) && (write(fd[1], gnl, ft_strlen(gnl)));
	return (close(fd[1]), fd[0]);
}

int	create_duping(t_redir *redir, t_env *myenv)
{
	int		fd;
	int		std;
	char	**file;

	(redir->typeredir == RIN || redir->typeredir == HEREDOC) && (std = 0);
	(redir->typeredir == ROUT || redir->typeredir == APPEND) && (std = 1);
	if (redir->typeredir != HEREDOC)
	{
		file = trans_list(redir->tok, myenv);
		if (file[1])
			return (fd_printf(2, "%s: ambiguous redirect\n", redir->tok->token),
				exit(1), 0);
		fd = open(file[0], redir->flags, 0664);
		if (fd == -1)
			return (perror(expand_prime(redir->tok->token, myenv)), exit(1), 0);
		if (dup2(fd, std) == -1)
			return (perror("dup2 "), exit(1), 0);
		return (close(fd), 1);
	}
	(redir->tok->hdoc && !redir->tok->down)
		&& (redir->fd_in = expand_herdoc(redir->fd_in, myenv));
	if (dup2(redir->fd_in, std) == -1)
		return (perror("dup2"), exit(1), 0);
	return (1);
}

void	exec_redir(t_ast *ast, t_env *myenv)
{
	int	pid;
	int	statu;

	pid = fork();
	if (pid == -1)
		return (perror("fork"));
	if (!pid)
	{
		while (ast && ast->type == REDIR && create_duping((t_redir *)ast,
				myenv))
			ast = ((t_redir *)ast)->trdr;
		execution(ast, &myenv);
		exit(0);
	}
	waitpid(pid, &statu, 0);
	exit_status(statu);
}
