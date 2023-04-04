/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:20:06 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/04 10:02:13 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void execution(t_ast **ast, t_env *myenv)
{
    if (!*ast)
        return;
    if ((*ast)->type == PIPE)
        exec_pipe(ast, myenv);
    else if ((*ast)->type == REDIR)
        exec_redir(ast, myenv);
    else
        exec_cmd(ast, myenv);
}