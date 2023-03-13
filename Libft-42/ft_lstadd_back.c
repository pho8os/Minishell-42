/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:24:58 by absaid            #+#    #+#             */
/*   Updated: 2023/03/13 21:29:57 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	addbenv(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
}
