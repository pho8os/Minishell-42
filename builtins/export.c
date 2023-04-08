/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:17 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/08 06:45:05 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"
//export TEST
//export a=(wc -l)
//echo "The current directory is: '"$(pwd)"'"
int check_id(char *ident, char *arg)
{
    if (!ft_isalpha(*ident) && *ident != '_')
        return (0);
    ident++;  
    while ((ft_isalnum(*ident) || *ident == '_') && *ident)
        ident++;
    if (*ident == '+' && !*(ident + 1) && ft_strchr(arg, '='))
        return (-1);
    if (!*ident)
        return (1);
    return (0);
}

void addvalue(t_env *myenv, char **sub, int prenv, int flag)
{
    char *tri;
    char *oldval;
    t_env *find;
    
    tri = ft_strtrim(sub[0], "+");
    find = ft_lstchr(myenv, tri);
    if (!prenv && find)
        return ;
    if (!find && !flag)
        return (addbenv(&myenv, newenv(tri, sub[1], prenv)));
    find->print = 1;    
    oldval = find->value;
    if (!flag)
        return(find->value = sub[1], free(NULL));
    return(find->value = ft_strjoin(oldval, sub[1]), free(NULL));
}

void export(t_env *myenv, char **arg)
{
    int i;
    char **sub;
    
    exit_status(myenv, 0);
    if (!arg[1] || !arg[1][0])
        return (print_export(myenv));
    i = 0;
    while (arg[++i])
    {
        sub = subbing(arg[i]);
        if (!check_id(sub[0], arg[i]))
        {
            fd_printf(2, "export: `%s': not a valid identifier\n", arg[i]); //ther is leaks here
            exit_status(myenv, 1);
        }
        else if (check_id(sub[0], arg[i]) == -1)
            addvalue(myenv,  sub, 1, 1);
        else if (check_id(sub[0], arg[i]) && !ft_strchr(arg[i], '='))   
            addvalue(myenv,  sub, 0, 0);
        else if (check_id(sub[0], arg[i]) && ft_strchr(arg[i], '='))
            addvalue(myenv,  sub, 1, 0);
    }
}