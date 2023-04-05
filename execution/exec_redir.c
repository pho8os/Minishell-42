/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:28:50 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/05 08:22:28 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int create_duping(t_redir *redir)
{
    int fd;
    int std;
    
    (redir->typeredir == RIN || redir->typeredir == HEREDOC) && (std = 0);
    (redir->typeredir == ROUT || redir->typeredir == APPEND) && (std = 1);
    if (redir->typeredir != HEREDOC)
    {
        fd = open(redir->arg, redir->flags, 0664);
        if (fd == -1)
            return (perror("open "), exit(1) ,0);
        if (dup2 (fd, std) == -1)
            return (perror("dup2 "), exit(1) ,0);
        close(fd);
    }
    else
        if (dup2 (redir->fd_in, std) == -1)
            return (perror("dup2 "), exit(1) ,0);
    return (1);        
}

void exec_redir(t_ast **ast, t_env *myenv)
{
    int pid;
    int status;

    pid = fork();
    if (pid == -1)
        return ;
    if (!pid)
    {
        while (*ast && (*ast)->type == REDIR && create_duping((t_redir *)*ast))
            (*ast) = ((t_redir *)*ast)->trdr;
        execution(ast, myenv);
        exit(0);
    }
    waitpid(pid, &status, 0);
    while (wait(NULL) != -1)
        ;
    exit_status(myenv, WEXITSTATUS(status));
}