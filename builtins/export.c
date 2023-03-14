/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:17 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/14 21:42:25 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
// $ export AAAAAAA
// export a+=g
//$ export AAA+PPP
//bash: export: `AAA+PPP': not a valid identifier
//$ export A="                AA+7=8"
//bash: export: `=                AA+7=8': not a valid identifier
//$ export A=                AA+7=8
//bash: export: `=                AA+7=8': not a valid identifier
void export(t_varibles *v, char **arg)
{
    int i;
    
    i = 0;
    if (!arg[1])
        print_env(v->myexp, "declare -x ", -1);
    
    // ft_lstclear(&v->myexp);
}