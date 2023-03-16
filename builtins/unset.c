/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:22 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/15 23:16:53 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

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

void unset(t_varibles *v, char **arg)
{
    int i;

    i = 0;
    while (arg[++i])
        unset_var(v->myenv, arg[i]);
    
}