/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:25:44 by absaid            #+#    #+#             */
/*   Updated: 2023/04/04 02:49:00 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_front(t_env **lst, t_env *new)
{
	if (!lst)
		return ;
	if (*lst == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}
