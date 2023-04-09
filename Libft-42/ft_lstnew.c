/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:25:51 by absaid            #+#    #+#             */
/*   Updated: 2023/04/09 13:12:17 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_env	*newenv(char *variable, char *value, int prenv)
{
	t_env	*node;

	node = gc(sizeof (t_env), 1, 0);
	node -> variable = variable;
	node -> value = value;
	node -> print = prenv;
	node -> prev = NULL;
	node -> next = NULL;
	return (node);
}
