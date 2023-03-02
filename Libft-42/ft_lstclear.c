/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:22 by absaid            #+#    #+#             */
/*   Updated: 2023/03/02 21:54:11 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
