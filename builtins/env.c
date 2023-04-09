/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:13 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/09 08:15:58 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void    env(t_env *myenv)
{
    set_statu(0);
    while (myenv)
    {
        if (myenv->print > 0)
            printf("%s=%s\n", myenv->variable, myenv->value);
        myenv = myenv->next;
    } 
}