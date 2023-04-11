/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_oper_subshell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:06:53 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 07:22:52 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_subshell(t_ast *ast, t_env *myenv)
{
	int	pid;
	int	stat;

	pid = fork();
	if (pid == -1)
		return (perror("fork"));
	if (!pid)
	{
		execution(((t_subsh *)ast)->sub, &myenv);
		exit(g_stat);
	}
	waitpid(pid, &stat, WUNTRACED);
	exit_status(stat);
}

void	exec_oper(t_ast *ast, t_env *myenv)
{
	execution(((t_operator *)ast)->left, &myenv);
	if (ast->type == AND && !g_stat)
		execution(((t_operator *)ast)->right, &myenv);
	if (ast->type == OR && g_stat)
		execution(((t_operator *)ast)->right, &myenv);
}
