/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:22:44 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/16 01:42:05 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void print_arg(char **arg)
{
	int i = -1;
	while (arg[++i])
	{
		printf("|%d| %s\n", i, arg[i]);
	}
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
    tm = a->prenv;
    a->prenv = b->prenv;
    b->prenv = tm;
}

void print_env(t_env *env, int flag)
{
    t_env *tmp;
    
    while (env && flag == 1)
    {
        // if (env->prenv)
            printf("%s=%s\n", env->variable, env->value);
        env = env->next;
    }
    while (env && flag == -1)
    {
        tmp = env;
        while (tmp)
        {
            if (ft_strcmp(env->variable, tmp->variable) >= 0)
                swap_data(env, tmp);
            tmp = tmp->next;
        }
        printf("declare -x %s=\"%s\"\n", env->variable, env->value);
        env = env->next;
    }   
}

void addvalue(t_varibles *v, const char *variable, char *value)
{
    t_env *find;
    
    find = ft_lstchr(v->myenv, variable);
    free(find->value);
    find->value = value;
}