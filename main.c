/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:54 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:55:30 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_varibles	v;

	(void)av;
	(void)ac;
	signal(SIGQUIT, SIG_IGN);
	dupenv(&v.myenv, env);
	gc(0, 0, 1);
	rl_catch_signals = 0;
	while (1)
	{
		signal(SIGINT, param_sig);
		v.cmdl = readline("minishell-$ ");
		if (v.cmdl == NULL)
			break ;
		v.tok = tokenizer(v.cmdl);
		v.ast = parser(&v.tok);
		execution(v.ast, &v.myenv);
		if (*v.cmdl)
			add_history(v.cmdl);
		free(v.cmdl);
		gc(0, 0, 0);
	}
	exit(g_stat);
}
