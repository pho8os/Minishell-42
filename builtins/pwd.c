/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:20 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/01 06:48:51 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void pwd(t_env *myenv)
{
    char pwd[PATH_MAX];
    
    exit_status(myenv, 0);
    getcwd(pwd, PATH_MAX);
    ft_putendl_fd(pwd, STDOUT_FILENO);
}