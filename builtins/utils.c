/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:22:44 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/14 21:56:50 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void print_env(t_env *penv, const char *str, int flag)
{
    while (penv)
    {
        (flag == 1) && printf("%s%s=%s\n",str, penv->variable, penv->value);
        (flag == -1) && printf("%s%s=\"%s\"\n",str, penv->variable, penv->value);
        penv = penv->next;
    }
}

void addboth(t_varibles *v, char *variable, char *value, int flag)
{
    if (variable && value && flag >= 0)
        addbenv(&v->myenv, newenv(variable, value));
    if (variable && value && flag <= 0)
        addbenv(&v->myexp, newenv(ft_strdup(variable), ft_strdup(value)));   
}

void addvalue(t_varibles *v, const char *variable, char *value, int flag)
{
    t_env *find;
    
    if (flag >= 0)
    {
        find = ft_lstchr(v->myenv, variable);
        free(find->value);
        find->value = value;
    }
    if (flag <= 0)
    {
        find = ft_lstchr(v->myexp, variable);
        free(find->value);
        find->value = ft_strdup(value);
    }
}