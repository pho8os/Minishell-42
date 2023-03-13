/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:54 by absaid            #+#    #+#             */
/*   Updated: 2023/03/13 21:03:51 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void print_tok(t_token *tok) //!!
{
	while (tok)
	{
		printf("|type = %d|   token = %s\n", tok->type, tok->token);
		tok = tok->next;
	}
	
}

int main(int ac, char **av, char **env)
{	
	char *cmdl;
	t_varibles v;
	
	(void)av;
	(void)ac;
	dupenv(env, &v);
	while(1)
	{
		cmdl = readline("minishell> ");
		if (cmdl == NULL)
			break;
		v.tok = lexer(cmdl);
		test_builting(&v);
		// rl_replace_line("New command", 0);
		// print_tok(tok);
		rl_redisplay();
		add_history(cmdl);
	}

}