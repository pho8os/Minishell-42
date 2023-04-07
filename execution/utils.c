/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:27:00 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/07 07:57:17 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int len_tab(char **s)
{
    int i;
    
    i = 0;
    while (s[i])
        i++;
    return(i);
}

char **join_tab(char **s1, char **s2, int i)
{
    int i;
    int j;
	char **strs;

    i = -1;
    strs = malloc(sizeof(char *) + (i + len_tab(s2) + 1));
    if (!strs)
        return (NULL);
    while (strs[++i])
        strs[i] = s1[i];
    j = 0;
    while (strs[i])
        strs[i++] = s2[j++];
    strs[i] = 0;
    return(strs);
}
