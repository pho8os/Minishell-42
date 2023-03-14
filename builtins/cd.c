/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:07 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/14 19:34:26 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
//unset OLDPWD
// cd -
//cd ~
void execd(t_varibles *v, const char *path)
{
    int ret;
    
    addvalue(v, "OLDPWD", getcwd(NULL, 0), 0);
    if (!path)
        return ;
    ret = chdir(path);
    if (ret != 0)
        perror(path);
}

void cd(t_varibles *v, char **arg)
{
    char *oldpwd;
    
    if (!ft_lstchr(v->myenv, "HOME") && !arg[1])
        return (ft_putendl_fd("home not set", 1));
    if (!ft_lstchr(v->myenv, "OLDPWD"))
        addboth(v, ft_strdup("OLDPWD"), getcwd(NULL, 0), 0);
    if ((!arg[1]))
        return (execd(v, ft_lstchr(v->myenv, "HOME")->value));
    if (!ft_memcmp("~", arg[2], 2))
        return (execd(v, ft_lstchr(v->myenv, "HOME")->value));
    oldpwd = ft_strdup(ft_lstchr(v->myenv, "OLDPWD")->value);
    // printf("== >%s\n", ft_lstchr(v->myenv, "OLDPWD")->value);
    if (!ft_memcmp("-", arg[2], 2))
        return (execd(v, oldpwd), free(oldpwd));
    return(execd(v, arg[2]), free(oldpwd));
}