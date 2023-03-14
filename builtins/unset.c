/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:22 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/14 23:56:09 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void delone_env(t_env **env)
{
    t_env *tmp;
    
    tmp = *env;
    if (!tmp->prev)
        return (*env = (*env)->next, (*env)->prev = NULL, free(tmp));
    if (!tmp->next)
        return (*env = (*env)->prev, (*env)->next = NULL, free(tmp));
    (*env) = (*env)->next;
    (*env)->prev = tmp->prev;
    (*env) = (*env)->prev;
    (*env)->next = tmp->next;
    free(tmp);
}

void unset_var(t_env *myenv, t_env *myexp, char *var)
{
    t_env *tmp;
    
    while (myenv)
    {
        tmp = ft_lstchr(myenv, var);
        if (!tmp)
        {
            
        }
        myenv = myenv->next;
    }
    
}

// void unset(t_varibles *v, char **arg)
// {

// }