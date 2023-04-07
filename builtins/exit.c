/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:15 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/07 10:32:02 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void ft_exit(t_env *myenv, char **arg)
{
    if (!arg[1])
        return(write(2,"exit\n", 5), exit(ft_atoi(myenv->value)));
    else if (!is_digit(arg[1])) 
        return(write(2,"exit\n", 5), write(2, "bash: exit: gdfgdfg: numeric argument required\n", 47), exit(255));
    else if (is_digit(arg[1]) && !arg[2])
        return(write(2,"exit\n", 5), exit(ft_atoi(arg[1]) % 256));
    else
        return(write(2, "bash: exit: too many arguments\n", 31), exit_status(myenv, 1));    
}