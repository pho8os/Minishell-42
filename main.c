/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:54 by absaid            #+#    #+#             */
/*   Updated: 2023/04/04 07:13:45 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// void print_tok(t_token *tok) //!!
// {
// 	t_token *tmp;

// 	while (tok)
// 	{
		
// 			// printf("len = %d\n", size_down(tok));
// 		tmp = tok->down;
// 		printf("\n!%s! |type = %d| |exp = %d|\n", tok->token, tok->type, tok->change);
// 		while (tmp)
// 		{
// 			printf("** !%s! |type = %d| |exp = %d| **", tmp->token, tmp->type, tmp->change);
// 			tmp = tmp->down;
// 		}
// 		puts("\n-----------");
// 		tok = tok->next;
// 	}
// 		// puts("\n-----------");
	
// }
void print_tok(t_token *tok) //!!
{
	t_token *tmp;

	while (tok)
	{
		
			// printf("len = %d\n", size_down(tok));
		tmp = tok->down;
		printf("\n!%s! |type = %d| |exp = %d|\n", tok->token, tok->type, tok->expand);
		while (tmp)
		{
			printf("** !%s! |type = %d| |exp = %d| **", tmp->token, tmp->type, tmp->expand);
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
	if (ast->type == PAR)
		print_tree(((t_subsh *)ast)->sub, sp);
	if (ast->type == REDIR)
        print_tree(((t_redir *)ast)->trdr, sp);	
	for (int i = 10; i < sp; i++)
        printf(" ");
	if (ast->type == AND || ast->type == OR || ast->type == PIPE)
		printf("type = %d   %s\n\n", ast->type, ((t_operator * )ast)->op);
	else if (ast->type == PAR)
		printf("type = %d (  )\n\n", ast->type);
	else if (ast->type == REDIR)
		printf("type = %d >?\n\n", ast->type);
	else
		print_down(((t_command *)ast)->list);
	if (ast->type == AND || ast->type == OR || ast->type == PIPE)
		print_tree(((t_operator * )ast)->left, sp);
}

int main(int ac, char **av, char **env)
{	
	char *cmdl;
	t_varibles v;
	
	
	(void)av;
	(void)ac;
	(void)env;

	dupenv(&v.myenv, env);
	while(1)
	{
		cmdl = readline("minishell> ");
		if (cmdl == NULL)
			break;
		v.tok = tokenizer(cmdl);	
		// v.tok = lexer(cmdl);
		// print_tok(v.tok);
		add_history(cmdl);
		v.ast = parser(&v.tok);
		// printf("== > %d\n", ((t_redr *)v.ast)->trdr->type);
		// execution(&v.ast, v.myenv);
		// printf("%s", cmdl);
		// test_builting(&v);
		print_tree(v.ast, 0);
		// rl_redisplay();
		// rl_replace_line("New command", 0);
		free(cmdl);
	}
}
