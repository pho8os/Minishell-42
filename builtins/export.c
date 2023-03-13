/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:17 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 21:02:37 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
//$ echo hdhhdh > $hhh"kkk"
// $ export AAAAAAA

void export(char **arg, t_varibles *v)
{
    int i;
    i = 0;
    if (!arg[1])
        while (v->myexp)
        {
            printf("declare -x %s=\"%s\"\n", v->myexp->variable, v->myexp->value);
            v->myexp = v->myexp->next;
        }

}