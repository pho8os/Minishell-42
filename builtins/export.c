/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:17 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 04:14:52 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
//$ echo hdhhdh > $hhh"kkk"
// $ export AAAAAAA

void export(char **arg, t_env **myenv, t_env **myexp)
{
    int i;
    myenv = 0;
    i = 0;
    if (!arg[1])
        while (*myexp)
        {
            printf("declare -x %s=\"%s\"\n", (*myexp)->variable, (*myexp)->value);
            (*myexp) = (*myexp)->next;
        }

}