/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:07 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 22:01:55 by yettabaa         ###   ########.fr       */
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

void cd(const char *path, t_varibles *v)
{
    if (!ft_lstchr(v->myenv, "OLDPWD"))
        addboth(v, ft_strdup("OLDPWD"), getcwd(NULL, 0), 0);
    else
        addboth(v, NULL, getcwd(NULL, 0), 0);
            
    // printf("%s\n", ft_lstchr(*myenv, "OLDPWD")->value);
    if (ft_strncmp("~", path, 1) == 0 || !path)
        cd_execute(getenv("HOME"));
    else    
        cd_execute(path);
}
