/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:08:12 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:48:25 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	*gc(size_t size, int param, int swap)
{
	static t_gc	*head;
	static t_gc	*head2;
	void		*address;
	static bool	mode;

	(swap == 1) && (mode = !mode);
	if (param == 1)
	{
		address = malloc(size);
		if (!address)
			return (ft_gcclear(&head), exit(1), NULL);
		(mode) && (gcadd_front(&head, ft_gcnew(address)), mode *= 1);
		(!mode) && (gcadd_front(&head2, ft_gcnew(address)), mode *= 1);
		return (address);
	}
	if (!param)
		ft_gcclear(&head);
	return (NULL);
}
