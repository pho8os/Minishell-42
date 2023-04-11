/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:20:06 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 08:41:25 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_ast *ast, t_env **myenv)
{
	signal(SIGINT, SIG_IGN);
	if (!ast)
		return ;
	if (ast->type == PIPE)
		exec_pipe(ast, *myenv);
	else if (ast->type == AND || ast->type == OR)
		exec_oper(ast, *myenv);
	else if (ast->type == REDIR)
		exec_redir(ast, *myenv);
	else if (ast->type == WORD)
		exec_cmd(ast, myenv);
	else if (ast->type == SUBSHELL)
		exec_subshell(ast, *myenv);
	else
		return ;
}
