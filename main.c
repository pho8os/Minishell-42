/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:32:54 by absaid            #+#    #+#             */
/*   Updated: 2023/03/02 21:40:04 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// t_list *dupenv(char **env)
// {
	
// }

int main(int ac, char **av, char **env)
{
	t_list *myenv;
	(void)av;
	(void)env;
	(void)ac;
	
	myenv = dupenv(env);
	if(ac > 1)
	{
		// while(1)
		// {
		// 	printf("%s",readline("shelllm9awd>"));
		// }
		lexer(av + 1);
	}
}