/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:22 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/01 06:50:44 by yettabaa         ###   ########.fr       */
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
            delone_env(&tmp);
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