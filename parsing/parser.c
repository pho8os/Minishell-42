/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:09:17 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:51:13 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*parser(t_token **tok)
{
	t_ast	*tree;

	if (!*tok || (*tok)->type == END)
		return (NULL);
	tree = parse_oper(tok);
	if ((!tree || (*tok)->type != END) && (*tok)->type != SIGHER)
	{
		set_statu(258);
		fd_printf(2, "Syntax : Error unexpected token `%s'\n", (*tok)->token);
		return (NULL);
	}
	return (tree);
}
