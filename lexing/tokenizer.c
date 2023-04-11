/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:30:23 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:47:35 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

void	norminit(t_norm *ptr)
{
	ptr->i = -1;
	ptr->token = 0;
	ptr->down = 0;
	ptr->dq = false;
	ptr->sq = false;
	ptr->space = true;
	ptr->op = 0;
	ptr->cp = 0;
}

void	norm_1(t_norm *n, char *c)
{
	(c[n->i] == '\'') && (n->sq = !n->sq);
	(c[n->i] == '\"') && (n->dq = !n->dq);
	(ft_strchr("|<>&", c[n->i]) && c[n->i] == c[n->i + 1]) && (n->x = 1);
	(c[n->i] != '\'' && c[n->i] != '\"') && (n->space = true);
	(c[n->i] == '(') && (n->op += 1);
	(c[n->i] == ')') && (n->cp += 1);
	if (!allspace(n->i, c) && c[n->i] != '\'' && c[n->i] != '\"'
		&& c[n->i] != ' ' && c[n->i] != '\t')
		addtok(&n->token, ft_newtoken(getflag(c[n->i], n->x), ft_substr(c, n->i,
					n->x + 1), 0, 0));
	if (c[n->i] == ' ' || c[n->i] == '\t')
	{
		while ((c[n->i] == ' ' || c[n->i] == '\t') && c[n->i])
			n->i++;
		n->i--;
	}
	n->i += n->x;
}

void	norm_2(t_norm *n, char *c)
{
	if (n->space)
	{
		addtok(&n->token, ft_newtoken(WORD, getq(c, &n->i, c[n->i - 1]),
				(n->dq == true), 0));
		n->space = false;
	}
	else if (!n->space)
	{
		n->down = lasttok(n->token);
		while (n->down->down)
			n->down = n->down->down;
		n->down->down = ft_newtoken(WORD, getq(c, &n->i, c[n->i - 1]),
				(n->dq == true), 0);
	}
}

void	norm_3(t_norm *n, char *c)
{
	if (n->space)
	{
		addtok(&n->token, ft_newtoken(WORD, getword(c, &n->i), 1, 1));
		n->space = false;
	}
	else if (!n->space)
	{
		n->down = lasttok(n->token);
		while (n->down->down)
			n->down = n->down->down;
		n->down->down = ft_newtoken(WORD, getword(c, &n->i), 1, 1);
	}
}

t_token	*tokenizer(char *c)
{
	t_norm	n;

	norminit(&n);
	while (c[++(n.i)])
	{
		n.x = 0;
		if ((n.sq && c[n.i] != '\'') || (n.dq && c[n.i] != '\"'))
			norm_2(&n, c);
		else if (ft_strchr("\"\'|<>&() \t", c[n.i]))
			norm_1(&n, c);
		else if (!ft_strchr("\"\'|<>&() \t", c[n.i]) && (!n.dq || !n.sq))
			norm_3(&n, c);
	}
	if ((n.sq || n.dq) || (n.op != n.cp))
		return (fd_printf(2, "Syntax : Quote Unfound\n"), NULL);
	if (n.op != n.cp)
		return (fd_printf(2, "Syntax : Need a parantes\n"), NULL);
	addtok(&n.token, ft_newtoken(END, ft_strdup("newline"), 0, 0));
	return (n.token);
}
