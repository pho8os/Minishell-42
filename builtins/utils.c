/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:22:44 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/10 11:31:00 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int is_digit(char *str)
{
    int i;

    i = -1;
    if(str[0] == '-' || str[0] == '+')
        i++;
    while (str[++i])
        if (!ft_isdigit(str[i]))
            return (0);
    return(1);
}

void swap_data(t_env *a, t_env  *b)
{
    int tm;
    char *c;

    c = a->variable;
    a->variable = b->variable;
    b->variable = c;
    c = a->value;
    a->value = b->value;
    b->value = c;
    tm = a->print;
    a->print = b->print;
    b->print = tm;
}

void print_export(t_env *myenv)
{
    t_env *exp;
    t_env *tmp;
    t_env *tmp2;
    
    exp = NULL;
    while (myenv)
    {
        addbenv(&exp, newenv(myenv->variable, myenv->value, myenv->print));
        myenv = myenv->next;
    }
    tmp2 = exp;
    while (exp)
    {
        tmp = exp;
        while (tmp)
        {
            if (ft_strcmp(exp->variable, tmp->variable) >= 0)
                swap_data(exp, tmp);
            tmp = tmp->next;
        }
        if (exp->print > 0)
            printf("declare -x %s=\"%s\"\n", exp->variable, exp->value);
        else if (exp->print == 0)
            printf("declare -x %s\n", exp->variable);
        exp = exp->next;
    }
    ft_lstclear(&tmp2);
}
