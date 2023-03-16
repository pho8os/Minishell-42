/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:54 by absaid            #+#    #+#             */
/*   Updated: 2023/03/16 04:11:04 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void print_tok(t_token *tok) //!!
{
	while (tok)
	{
		printf("!%s! |type = %d|   *=*   ", tok->token, tok->type);
		tok = tok->next;
	}
	puts("\n");
	
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
		puts("*====================================*\n");
		print_tok(v.tok);
		puts("*====================================*");
		pwd();
		test_builting(&v);
		// rl_replace_line("New command", 0);
		rl_redisplay();
		add_history(cmdl);
		free(cmdl);
	}

}