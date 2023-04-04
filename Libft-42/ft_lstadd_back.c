/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:24:58 by absaid            #+#    #+#             */
/*   Updated: 2023/04/04 02:47:15 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	addbenv(t_env **lst, t_env *new)
{
	t_env	*tmp;
	
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}
