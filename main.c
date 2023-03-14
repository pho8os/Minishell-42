/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:54 by absaid            #+#    #+#             */
/*   Updated: 2023/03/14 19:19:37 by yettabaa         ###   ########.fr       */
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
	(void)env;
	dupenv(env, &v);
	while(1)
	{
		cmdl = readline("minishell> ");
		if (cmdl == NULL)
			break;
		v.tok = lexer(cmdl);
		print_tok(v.tok);
		test_builting(&v);
		pwd();
		// rl_replace_line("New command", 0);
		rl_redisplay();
		add_history(cmdl);
		free(cmdl);
	}

}