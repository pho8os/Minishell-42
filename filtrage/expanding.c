/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 05:24:25 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/01 06:38:49 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"
//$"P"
// echo "$"PATH
int check_exp(char *exp)
{
    if (*exp == '?')
        return (-2);
    if (ft_isdigit(*exp))
        return (-1);
    if (!ft_isalpha(*exp) && *exp != '_')
        return (0);
    exp++;  
    while ((ft_isalnum(*exp) || *exp == '_') && *exp)
        exp++;
    if (!*exp)
        return (1);
    return (0);
}
// free
char *expand(t_token *list, t_env *myenv)
{
    t_env *find;

    if (list->change == NUL || !check_exp(list->token + 1))
        return (list->token);
    if (check_exp(list->token + 1) == -1)
        return (list->token + 2);
    if (check_exp(list->token + 1) == -2)
        return (ft_strjoin(ft_lstchr(myenv, "?")->value ,list->token + 2));
    find = ft_lstchr(myenv, list->token + 1);
    if (!find)
        return(ft_strdup(""));
    return (find->value);    
}

void exit_status(t_env *myenv ,int status)
{
    t_env *find;

    find = ft_lstchr(myenv, "?");
    ///free 
    find->value = ft_itoa(status);
}
// char *expand(t_varibles v, char *exp)
// {
//     t_env *find;

//     if (!check_exp(exp + 1))
//         return (exp);
//     if (check_exp(exp + 1) == -1)
//         return (exp + 2);
//     find = ft_lstchr(v.myenv, exp + 1);
//     if (!find)
//         return(ft_strdup(""));
//     return (find->value);    
// }