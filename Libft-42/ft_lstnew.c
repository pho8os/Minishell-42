/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:25:51 by absaid            #+#    #+#             */
/*   Updated: 2023/04/10 12:17:34 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_env	*newenv(char *variable, char *value, int prenv)
{
	t_env	*node;

	node = malloc(sizeof (t_env));
	if (!node)
		return (NULL);
	node -> variable = variable;
	node -> value = value;
	node -> print = prenv;
	node -> next = NULL;
	return (node);
}
