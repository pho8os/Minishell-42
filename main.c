/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:54 by absaid            #+#    #+#             */
/*   Updated: 2023/03/12 03:15:07 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char **subbing(char *env)
{
	int i;
	char **varandval;
	
	i = 0;
	while(env[++i])
		if(env[i] == '=')
			break;
	varandval = malloc(sizeof(char *) * 2);
	if (!varandval)
		return(NULL);
	varandval[0] = ft_substr(env, 0, i);
	varandval[1] = ft_substr(env, i + 1, ft_strlen(env + i));
	if(!ft_strncmp("SHLVL", varandval[0], 6))
	{
		i = ft_atoi(varandval[1]);
		(i >= 0) && (i++);
		(i < 0) && (i = 0);
		free(varandval[1]);
		varandval[1] = ft_itoa(i);
	}
	return(varandval);
}

t_env *dupenv(char **env)
{
	t_env *head;
	char **varandval;
	
	head  = NULL;
	while(*env)
	{
		varandval = subbing(*env);
		// printf("%s=%s\n", varandval[0], varandval[1]);
		ft_lstadd_back(&head, ft_lstnew(varandval[0], varandval[1]));
		env++;
	}
	return (head);
}

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
	
	(void)av;
	(void)ac;
	myenv = dupenv(env);
	while(1)
	{
		cmdl = readline("minishell> ");
		tok = lexer(cmdl);
		test_builting(tok, myenv);
		// rl_replace_line("New command", 0);
		// print_tok(tok);
		rl_redisplay();
		add_history(cmdl);
	}

}