/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:34:18 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/30 22:15:02 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int chek_back(char *str, char c, int star, int end)
{
    while (star >= end)
    {
        if (str[star] == c)
            return (0);
        star--; 
    }
    return(1);
}