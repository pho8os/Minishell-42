/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:54 by absaid            #+#    #+#             */
/*   Updated: 2023/04/08 08:10:25 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"


void print_tok(t_token *tok) //!!
{
	t_token *tmp;

	while (tok)
	{
		
			// printf("len = %d\n", size_down(tok));
		tmp = tok->down;
		printf("\n!%s! |type = %d| |hdoc = %d|\n", tok->token, tok->type, tok->hdoc);
		while (tmp)
		{
			printf("** !%s! |type = %d| |hdoc = %d| **", tmp->token, tmp->type, tmp->hdoc);
			tmp = tmp->down;
		}
		puts("\n-----------");
		tok = tok->next;
	}
		// puts("\n-----------");
	
}

void print_down(t_token *tok)
{
	t_token *tmp;
	// while (tok->type != END)
	while (tok && tok->type != END)
	{
		tmp = tok->down;
		printf("|type = %d| ", tok->type);
		printf("%s",tok->token);
		while (tmp)
		{
			printf("%s",tmp->token);
			tmp = tmp->down;
		}
		printf(" ");
		tok = tok->next;
	}
	printf("\n\n");
	
}

void print_tree(t_ast *ast, int sp)
{
	if (!ast)
		return ;
	sp += 10;
	if (ast->type == AND || ast->type == OR || ast->type == PIPE)
		print_tree(((t_operator * )ast)->right, sp);	
	if (ast->type == SUBSHELL)
		print_tree(((t_subsh *)ast)->sub, sp);
	if (ast->type == REDIR)
        print_tree(((t_redir *)ast)->trdr, sp);	
	for (int i = 10; i < sp; i++)
        printf(" ");
	if (ast->type == AND)
		printf("type = %d  && \n\n", ast->type);
	else if (ast->type == OR )
		printf("type = %d  || \n\n", ast->type);
	else if (ast->type == PIPE)
		printf("type = %d  | \n\n", ast->type);
	else if (ast->type == SUBSHELL)
		printf("type = %d (  )\n\n", ast->type);
	else if (ast->type == REDIR)
		printf("type = %d arg = %s in = %d \n\n", ((t_redir *)ast)->typeredir, ((t_redir *)ast)->tok->token, ((t_redir *)ast)->fd_in);
	else
		print_down(((t_command *)ast)->list);
	if (ast->type == AND || ast->type == OR || ast->type == PIPE)
		print_tree(((t_operator * )ast)->left, sp);
}

int main(int ac, char **av, char **env)
{
	t_varibles v;
	(void)av;
	(void)ac;
	signal(SIGQUIT, SIG_IGN);
	dupenv(&v.myenv, env);
	rl_catch_signals = 0; // 
	while(1)
	{
		signal(SIGINT, param_sig);
		v.cmdl = readline("minishell-$ ");
		if (v.cmdl == NULL)
			break;
		v.tok = tokenizer(v.cmdl);
		// print_tok(v.tok);
		v.ast = parser(&v.tok, v.myenv);
		// print_tree(v.ast, 0);
		execution(v.ast, v.myenv);
		if (*v.cmdl)
			add_history(v.cmdl);
		free(v.cmdl);
	}
	exit(_stat(v.myenv));
}
