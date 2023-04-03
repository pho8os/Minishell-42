/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:40:58 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/01 02:41:10 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int left_pipe(t_ast **ast, int fd[2],t_env *myenv)
{
    pid_t pid;
    
    pid = fork();
    if (pid == -1)
        return (perror("fork failed") ,0);
    if (!pid)
    {
        if (dup2(fd[1], 1) == -1)
            return (perror("dup2 failed") ,exit(1), 0);
        close(fd[0]);
        close(fd[1]);
        execution(&((t_operator *)*ast)->left, myenv);
        exit(0);
    }
    return(1);
}

int right_pipe(t_ast **ast, int fd[2],t_env *myenv)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
        return (perror("fork failed") ,0);
    if (!pid)
    {
        if (dup2(fd[0], 0) == -1)
            return (perror("dup2 failed") ,exit(1), 0);
        close(fd[0]);  
        close(fd[1]);
        execution(&((t_operator *)*ast)->right, myenv);
        exit(0); 
    }
    return(1);
}

void exec_pipe(t_ast **ast, t_env *myenv)
{
    int fd[2];
    
    if (pipe(fd) == -1)
        return (perror("Pipe filed"));   
    if (!left_pipe(ast, fd, myenv) || !right_pipe(ast, fd, myenv))
        return ;
    close(fd[0]);
    close(fd[1]);  
    wait(NULL);
    wait(NULL);
    // while (wait(NULL) != -1)
    //     ;
}