/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:20:04 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/10 11:32:15 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_env **lst)
{
	t_env	*c;

	if (!lst)
		return ;
	c = *lst;
	while (c)
	{
		if (c->next == NULL)
			break ;
		c = c->next;
		free(*lst);
		*lst = c;
	}
	free(*lst);
	*lst = NULL;
}

void delete_node(t_env **head, char *var)
{
    t_env *current = *head;
    t_env *prev = NULL;

    while (current != NULL && ft_memcmp(current->variable, var, ft_strlen(var) + 1) != 0)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL) 
        return; // node not found
    if (prev == NULL) // if node to delete is the head
        *head = current->next;
    else 
        prev->next = current->next;
    free(current->variable);    
    free(current->value);    
    free(current);
}
