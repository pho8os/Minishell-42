/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_priorities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:58:46 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 08:51:00 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*parse_cmd(t_token **tok)
{
	t_ast	*ast;
	t_token	*tmp;

	if ((*tok)->type == OPAR)
		return (parse_sub(tok));
	if ((*tok)->type == WORD)
	{
		tmp = *tok;
		while ((*tok)->type == WORD && (*tok)->type != END)
			*tok = (*tok)->next;
		return (ast = new_cmd(tmp), ast);
	}
	return (NULL);
}

t_ast	*parse_redir(t_token **tok)
{
	t_ast	*ast;
	t_ast	*reder;

	ast = parse_cmd(tok);
	if ((*tok)->type == RIN || (*tok)->type == ROUT || (*tok)->type == HEREDOC
		|| (*tok)->type == APPEND)
	{
		reder = redire_info(tok);
		if (!reder)
			return (NULL);
		while ((*tok)->type != AND && (*tok)->type != OR && (*tok)->type != PIPE
			&& (*tok)->type != END)
		{
			if ((*tok)->type != WORD && !addback_redir(reder, redire_info(tok)))
				return (NULL);
			(!ast && (*tok)->type == WORD) && (ast = parse_cmd(tok));
			if (ast && (*tok)->type == WORD)
				addb_list(ast, tok);
		}
		return (addback_redir(reder, ast), reder);
	}
	return (ast);
}

t_ast	*parse_sub(t_token **tok)
{
	t_ast	*ast;

	*tok = (*tok)->next;
	if ((*tok)->type == CPAR)
		return (NULL);
	while ((*tok)->type != CPAR)
	{
		ast = new_sub(parse_oper(tok));
		if (!((t_subsh *)ast)->sub)
			return (NULL);
	}
	*tok = (*tok)->next;
	return (ast);
}

t_ast	*parse_pipe(t_token **tok)
{
	t_ast	*ast;

	ast = parse_redir(tok);
	if (!ast)
		return (NULL);
	while ((*tok)->type == PIPE)
	{
		*tok = (*tok)->next;
		ast = new_oper(PIPE, ast, parse_redir(tok));
		if (!((t_operator *)ast)->right)
			return (NULL);
	}
	return (ast);
}

t_ast	*parse_oper(t_token **tok)
{
	t_ast	*ast;

	ast = parse_pipe(tok);
	if (!ast)
		return (NULL);
	while (((*tok)->type == AND || (*tok)->type == OR))
	{
		ast = new_oper((*tok)->type, ast, NULL);
		*tok = (*tok)->next;
		((t_operator *)ast)->right = parse_pipe(tok);
		if (!((t_operator *)ast)->right)
			return (NULL);
	}
	return (ast);
}
