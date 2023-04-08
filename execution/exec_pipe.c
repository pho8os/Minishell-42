/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:40:58 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/08 06:38:41 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int pipe_root(t_ast *ast, t_env *myenv, int fd[2], int std)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
        return (perror("fork") ,0);
    if (!pid)
    {
        if (dup2(fd[std], std) == -1)
            return (perror("dup2") ,exit(1), 0);
        close_pipe(fd);    
        execution(ast, myenv);
        exit(_stat(myenv));
    }
    return(1);
}

void exec_pipe(t_ast *ast, t_env *myenv)
{
    int fd[2];
    int statu;
    
    if (pipe(fd) == -1)
        return (perror("Pipe filed"));   
    if (!pipe_root(((t_operator *)ast)->left, myenv, fd, LEFT) || !pipe_root(((t_operator *)ast)->right, myenv, fd, RIGHT))
        return ;
    close_pipe(fd);
    wait(&statu);
    exit_status(myenv, WEXITSTATUS(statu));
    wait(&statu);
    exit_status(myenv, WEXITSTATUS(statu));
}