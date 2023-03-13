/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:20 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 05:31:09 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void pwd(void)
{
    char pwd[PATH_MAX];
    
    getcwd(pwd, PATH_MAX);
    ft_putendl_fd(pwd, STDOUT_FILENO);
}