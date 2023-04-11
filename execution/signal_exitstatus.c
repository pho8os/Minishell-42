/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_exitstatus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 04:54:10 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 08:38:39 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	param_sig(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	set_statu(1);
}

void	exit_status(int status)
{
	if (WIFEXITED(status))
		g_stat = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_stat = 128 + WTERMSIG(status);
}

void	set_statu(int status)
{
	g_stat = status;
}
