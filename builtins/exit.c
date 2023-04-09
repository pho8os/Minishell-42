/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:15 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/09 13:01:51 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void ft_exit(char **arg)
{
    if (!arg[1])
        return(write(2,"exit\n", 5), exit(g_stat));
    else if (!is_digit(arg[1])) 
        return(fd_printf(2, "exit\nexit: %s: numeric argument required\n", arg[1]), exit(255));
    else if (is_digit(arg[1]) && !arg[2])
    {
        puts("exit");
       long long int a = ft_atoi(arg[1]);
        if(a < 0)
        {
            fd_printf(2, "%d\nexit: %s: numeric argument required\n", a,arg[1]);
            a = 255;
        }

        return(exit(a % 256));

    }
    else
        return(write(2, "bash: exit: too many arguments\n", 31), set_statu(1)); 
}