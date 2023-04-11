/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:20 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 07:10:29 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	char	pwd[PATH_MAX];

	set_statu(0);
	getcwd(pwd, PATH_MAX);
	ft_putendl_fd(pwd, STDOUT_FILENO);
}
