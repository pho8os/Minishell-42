/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:28:50 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/08 09:58:24 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int expand_herdoc(int fd_in, t_env *myenv)
{
    int fd[2];
    char *gnl;
    
    if (pipe(fd) == -1)
        return (exit(1), write(2, "pipe_expand_herdoc", 18)); //signal
    gnl = expand_prime(get_next_line(fd_in), myenv);
    while (gnl)
    {
        write(fd[1], gnl, ft_strlen(gnl));
        gnl = expand_prime(get_next_line(fd_in), myenv);
    }
    (gnl) && (write(fd[1], gnl, ft_strlen(gnl)));
    return(close(fd[1]), fd[0]);
}

int create_duping(t_redir *redir, t_env *myenv)
{
    int fd;
    int std;

    (redir->typeredir == RIN || redir->typeredir == HEREDOC) && (std = 0);
    (redir->typeredir == ROUT || redir->typeredir == APPEND) && (std = 1);
    if (redir->typeredir != HEREDOC)
    {
        fd = open(redir->tok->token, redir->flags, 0664);
        if (fd == -1)
            return (perror(redir->tok->token), exit(1) ,0);
        if (dup2 (fd, std) == -1)
            return (perror("dup2 "), exit(1) ,0);
        return (close(fd), 1);
    }
    (redir->tok->hdoc && !redir->tok->down) && (redir->fd_in = expand_herdoc(redir->fd_in, myenv));
    if (dup2 (redir->fd_in, std) == -1)
        return (perror("dup2"), exit(1) ,0);
    return(1);        
}

void exec_redir(t_ast *ast, t_env *myenv)
{
    int pid;
    int statu;

    pid = fork();
    if (pid == -1)
        return ;
    if (!pid)
    {
        while (ast && ast->type == REDIR && create_duping((t_redir *)ast, myenv))
            ast = ((t_redir *)ast)->trdr;
        execution(ast, myenv);
        exit(0);
    }
    waitpid(pid, &statu, 0);
    exit_status(myenv, WEXITSTATUS(statu));
}