/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:11 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/16 05:45:53 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

//$ echo hdhhdh > $hhh"kkk"
// echo -nnnnnnnnnnnnnn
//echo -nnnnn -nnnnn  -nnnnnn     -nnnnnnnnnnn -nn -n -n -n yas
//echo -nnnnn -nnnnn  -nnnnnn     -nnnn-nnnnnnn -nn -n -n -n yas
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

void echo(t_varibles *v, char **arg)
{
    (void)v;
    int i;
    char *str;
    
    i = -1;
    str = NULL;
    while (arg[++i])
    {
        if (valid_option(arg[0]) && !valid_option(arg[i]))
            str = ft_strjoin_sp(str, arg[i], ' ');
        else if (!valid_option(arg[0]))
            str = ft_strjoin_sp(str, arg[i], ' ');
    }
    if (valid_option(arg[0]))`
        ft_putstr_fd(str, 1);
    else        
        ft_putendl_fd(str, 1);
}