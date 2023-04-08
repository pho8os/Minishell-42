/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:11 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/08 05:10:47 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int valid_option(char *arg)
{
    int i;

    i = 0;
    if ((arg[i] != '-') || (arg[i] == '-' && arg[1] != 'n'))
        return (0);
    while (arg[++i])
    {
        if(arg[0] != '-' || arg[i] != 'n')
            return (0);
    }
    return (1);
}

void echo(t_env *myenv, char **arg)
{
    int i;
    char *str;
    
    exit_status(myenv, 0);
    if (!arg[1])
        return (ft_putendl_fd("", 1));
    str = NULL;
    i = 0;
    while (arg[++i])
    {
        if (valid_option(arg[1]) && !valid_option(arg[i]))
            str = ft_strjoin_sp(str, arg[i], ' ');
        else if (!valid_option(arg[1]))
            str = ft_strjoin_sp(str, arg[i], ' ');
    }
    if (valid_option(arg[1]))
        return (ft_putstr_fd(str, 1), free(str));
    return (ft_putendl_fd(str, 1), free(str));
}