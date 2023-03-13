/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:13 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 02:09:40 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void print_env(t_env *myenv)
{
    while (myenv)
    {
        printf("%s=%s\n", myenv->variable, myenv->value);
        myenv = myenv->next;
    }
}