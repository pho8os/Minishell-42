/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:22 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/10 11:16:17 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

static int check_id(char *ident)
{
    if (!ft_isalpha(*ident) && *ident != '_')
        return (0);
    ident++;  
    while ((ft_isalnum(*ident) || *ident == '_') && *ident)
        ident++;
    if (!*ident)
        return (1);
    return (0);
}



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
    set_statu(0);
    while (arg[++i])
    {
        if (check_id(arg[i]))
            delete_node(&myenv, arg[i]);
        else
        {
            fd_printf(2, "unset: `%s': not a valid identifier\n", arg[i]);
            set_statu(1);
        }
    }
}