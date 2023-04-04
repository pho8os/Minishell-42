/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:22 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/04 05:24:03 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void unset_var(t_env *myenv, char *var)
{
    t_env *tmp;
    
    while (myenv)
    {
        tmp = ft_lstchr(myenv, var);
        if (tmp)
            tmp->print = -2;
        myenv = myenv->next;
    }
}

void unset(t_env *myenv, char **arg)
{
    int i;

    i = -1;
    exit_status(myenv, 0);
    while (arg[++i])
        unset_var(myenv, arg[i]);
}