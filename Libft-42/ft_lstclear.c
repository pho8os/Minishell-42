/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:22 by absaid            #+#    #+#             */
/*   Updated: 2023/03/15 01:30:45 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
    return (free(tmp->variable), free(tmp->value), free(tmp));
}

void	ft_lstclear(t_env **lst)
{
	t_env	*tmp;
	t_env	*t;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		t = tmp;
		tmp = tmp->next;
		free(t->variable);
		free(t->value);
		free(t);
	}
	*lst = NULL;
}
