/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:40:58 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/06 01:11:55 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int pipe_root(t_ast *ast, t_env *myenv, int fd[2], int std)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
        return (perror("fork failed") ,0);
    if (!pid)
    {
        if (dup2(fd[std], std) == -1)
            return (perror("dup2 failed") ,exit(1), 0);
        close(fd[0]);  
        close(fd[1]);
        execution(ast, myenv);
        exit(0); 
    }
    return(1);
}

void exec_pipe(t_ast *ast, t_env *myenv)
{
    int fd[2];
    
    if (pipe(fd) == -1)
        return (perror("Pipe filed"));   
    if (!pipe_root(((t_operator *)ast)->left, myenv, fd, LEFT) || !pipe_root(((t_operator *)ast)->right, myenv, fd, RIGHT))
        return ;
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    // while (wait(NULL) != -1)
    //     ;
}