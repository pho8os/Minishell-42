/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_oper_subshell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:06:53 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/08 05:09:48 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void exec_subshell(t_ast *ast, t_env *myenv)
{
    int pid;
    int stat;
    
    pid = fork();
    if (pid == -1)
        return ;
    if (!pid)
    {
        execution(((t_subsh *)ast)->sub, myenv);
        exit(_stat(myenv));
    }
    waitpid(pid, &stat, WUNTRACED);
    exit_status(myenv, WEXITSTATUS(stat));
}

void exec_oper(t_ast *ast, t_env *myenv)
{
    execution(((t_operator *)ast)->left, myenv);
    if (ast->type == AND && !_stat(myenv))
        execution(((t_operator *)ast)->right, myenv);
    if (ast->type == OR && _stat(myenv))
        execution(((t_operator *)ast)->right, myenv);
}
