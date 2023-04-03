/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:58:56 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/29 03:32:36 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(void)
{
	t_token	*head;
	int		i;
	int		f;
    
    f= 0;
	head = NULL;
    for (int j = 0; j < 10; j++)
	    (!f) && (i++);

    
	// addtok(&head, newtok(0, ft_strdup("1"), 0));
	// addtok(&head, newtok(0, ft_strdup("2"), 0));
	// addtok_down(&head, newtok(0, ft_strdup("1*"), 0));
	// addtok_down(&head, newtok(0, ft_strdup("2*"), 0));
	// addtok_down(&head, newtok(0, ft_strdup("3*"), 0));
	// addtok(&head, newtok(0, ft_strdup("3"), 0));
	// printf("%s\n", head->next->down->down->down->token);
    printf("%d\n", i);
}
