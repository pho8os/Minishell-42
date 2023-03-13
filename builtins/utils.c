/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:22:44 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 22:03:50 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void addboth(t_varibles *v, char *variable, char *value, int flag)
{
    if (variable && value && flag >= 0)
        addbenv(&v->myenv, newenv(variable, value));
    if (variable && value && flag <= 0)
        addbenv(&v->myexp, newenv(variable, value));   
}

void addvalue(t_varibles *v, char *variable, char *value, int flag)
{
    
}