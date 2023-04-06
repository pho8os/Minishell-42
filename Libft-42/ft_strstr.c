/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 08:23:11 by absaid            #+#    #+#             */
/*   Updated: 2023/04/06 06:20:52 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = -1;
	if (to_find[0] == '\0')
		return (str);
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
	}
	return (0);
}
