/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:25:51 by absaid            #+#    #+#             */
/*   Updated: 2023/03/13 21:30:22 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_env	*newenv(char *variable, char *value)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof (t_env));
	if (!node)
		return (NULL);
	node -> variable = variable;
	node-> value = value;
	node -> next = NULL;
	return (node);
}
