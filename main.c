/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:54 by absaid            #+#    #+#             */
/*   Updated: 2023/03/13 04:53:33 by yettabaa         ###   ########.fr       */
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
	t_token *tok;
	t_env *myenv;
	t_env *myexp;
	
	(void)av;
	(void)ac;
	dupenv(env, &myenv, &myexp);
	while(1)
	{
		cmdl = readline("minishell> ");
		tok = lexer(cmdl);
		test_builting(tok, &myenv, &myexp);
		// rl_replace_line("New command", 0);
		// print_tok(tok);
		rl_redisplay();
		add_history(cmdl);
	}

}