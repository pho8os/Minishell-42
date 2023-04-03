/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_const.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:09:15 by absaid            #+#    #+#             */
/*   Updated: 2023/04/03 09:17:08 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_ast	*new_oper(int type, t_ast *left, t_ast *right, char *op)
{
	t_operator	*operator;
	
	operator = malloc(sizeof(t_operator));
    if (!operator)
        return (NULL);
    operator->op = op;
    operator->type = type;
    operator->left = left;
    operator->right = right;
	return ((t_ast *)operator);
}

t_ast *new_reder(void)
{
    t_redr *redirection;
    
    redirection = malloc(sizeof(t_redr));
    if (!redirection)
        return (NULL);
    redirection->type =  REDIR;
    redirection->trdr = NULL;
    return ((t_ast *)redirection);   
}

t_ast *new_sub(t_ast *tree)
{
    t_subsh *sub;

    sub = malloc(sizeof(t_subsh));
    if (!sub)
        return (NULL);
    sub->type =  PAR;
    sub->sub = tree;
    return ((t_ast *)sub);
}

t_ast	*new_cmd(t_token *list)
{
    t_token *tmp;
	t_command	*command;

	command = malloc(sizeof(t_command));
    if (!command)
        return (NULL);
    command->type = WORD;
    command->list = list;
    tmp =list;
    while ((tmp)->type == WORD && (tmp)->type != END)
        tmp = tmp->next;
    tmp = tmp->prev;
    tmp->next = NULL;
	return ((t_ast *)command);
}
