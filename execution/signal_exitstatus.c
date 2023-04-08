/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_exitstatus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 04:54:10 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/08 06:18:28 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exit_status(t_env *myenv ,int status)
{
    // if (WIFEXITED)
        myenv->value = ft_itoa(status);
}

int _stat(t_env *myenv)
{
    return(ft_atoi(myenv->value));
}

void param_sig(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}