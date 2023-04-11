/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:14:13 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:48:42 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	ft_gcclear(t_gc **g)
{
	t_gc	*node;

	while (*g)
	{
		node = *g;
		*g = (*g)->next;
		free(node->ptr);
		free(node);
		node = NULL;
	}
	g = NULL;
}

t_gc	*ft_gcnew(void *ptr)
{
	t_gc	*g;

	g = malloc(sizeof(t_gc));
	if (!g)
		return (NULL);
	return (g->ptr = ptr, g->next = NULL, g);
}

void	gcadd_front(t_gc **gc, t_gc *g)
{
	(*gc) && (g->next = *gc);
	*gc = g;
}
