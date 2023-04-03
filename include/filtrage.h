/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtrage.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:24:14 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/01 06:39:05 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTRAGE_H
# define FILTRAGE_H

// char *expand(t_varibles v, char *exp);
char *expand(t_token *list, t_env *myenv);
void exit_status(t_env *myenv ,int status);
#endif