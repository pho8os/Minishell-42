/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:13 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/07 10:44:11 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void    env(t_env *myenv)
{
    exit_status(myenv, 0);
    while (myenv)
    {
        if (myenv->print > 0)
            printf("%s=%s\n", myenv->variable, myenv->value);
        myenv = myenv->next;
    } 
}