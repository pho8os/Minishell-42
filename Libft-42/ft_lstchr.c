/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 05:18:18 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 05:53:42 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env *ft_lstchr(t_env *lst, const char *variable)
{
    if (!lst)
        return (NULL);
    while (lst)
    {
        if (!ft_strcmp(lst->variable, variable))
            return(lst);
        lst = lst->next;
    }
    return (lst);
}