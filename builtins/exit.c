/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:15 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/09 08:32:54 by yettabaa         ###   ########.fr       */
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
        return(write(2,"exit\n", 5), exit(ft_atoi(arg[1]) % 256));
    else
        return(write(2, "bash: exit: too many arguments\n", 31), set_statu(1)); 
}