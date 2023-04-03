/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:12 by absaid            #+#    #+#             */
/*   Updated: 2023/04/01 02:43:21 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

void execution(t_ast **ast, t_env *myenv);
void exec_pipe(t_ast **ast, t_env *myenv);
void exec_cmd(t_ast **ast, t_env *myenv);

#endif