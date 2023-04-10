/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 05:18:18 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/10 02:18:08 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env *ft_lstchr(t_env *lst, const char *variable)
{
    int len;
    
    if (!lst)
        return (NULL);
    len = ft_strlen(variable);
    while (lst)
    {
        // if (!ft_memcmp(lst->variable, variable, len + 1) && lst->print != -2)
        if (lst->print != -2 && !ft_strcmp(lst->variable, variable))
            return(lst);
        lst = lst->next;
    }
    return (NULL);
}
