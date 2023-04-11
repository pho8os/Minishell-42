/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:08:39 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:48:05 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
}				t_gc;

void			*gc(size_t size, int param, int swap);
void			ft_gcclear(t_gc **g);
t_gc			*ft_gcnew(void *ptr);
void			gcadd_front(t_gc **gc, t_gc *g);
#endif