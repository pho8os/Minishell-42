/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:15 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/10 05:47:56 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void ft_exit(char **arg)
{
    long long int a;

    if (!arg[1])
        return(write(2,"exit\n", 5), exit(g_stat));
    else if (!is_digit(arg[1])) 
        return(fd_printf(2, "exit\nexit: %s: numeric argument required\n", arg[1]), exit(255));
    else if (is_digit(arg[1]) && !arg[2])
    {
        a = ft_atoi(arg[1]);
        if(a < 0)
            return(a = 255, fd_printf(2, "exit\nexit: %s: numeric argument required\n", arg[1]), exit(a % 256));
        return(fd_printf(2, "exit\n"), exit(a % 256));
    }
    else
        return(fd_printf(2, "exit\nexit: too many arguments\n"), set_statu(1)); 
}