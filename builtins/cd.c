/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:07 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 05:46:11 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
//unset OLDPWD
// cd -
void cd_execute(const char *path)
{
    int ret;
    
    ret = chdir(path);
    if (ret != 0)
        perror(path);
}

void cd(const char *path, t_env **myenv, t_env **myexp)
{
    if (!ft_lstchr(*myenv, "OLDPWD"))
    {
        ft_lstadd_back(myenv, ft_lstnew(ft_strdup("OLDPWD"), getcwd(NULL, 0)));
        ft_lstadd_back(myexp, ft_lstnew(ft_strdup("OLDPWD"), getcwd(NULL, 0)));
    }
    // printf("%s\n", ft_lstchr(*myenv, "OLDPWD")->value);
    if (ft_strncmp("~", path, 1) == 0 || !path)
        cd_execute(getenv("HOME"));
    else    
        cd_execute(path);
}
