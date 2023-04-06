/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:29:36 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/06 08:40:47 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_new(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char	*stock_str(char *stock)
{
	char	*new_s;

	if (ft_strchr(stock, '\n'))
	{
		new_s = ft_strdup(ft_strchr(stock, '\n') + 1);
		free(stock);
		return (new_s);
	}
	new_s = NULL;
	return (new_s);
}

static char	*stop_at_nel(char *stock)
{
	char	*gnl;

	if (!stock)
		return (NULL);
	if (stock[0] == '\0')
		return (free(stock), NULL);
	if (ft_strchr(stock, '\n'))
	{
		gnl = ft_substr(stock, 0, len_new(stock) + 1);
		return (gnl);
	}
	else
	{
		gnl = ft_strdup(stock);
		free(stock);
		stock = NULL;
	}
	return (gnl);
}

char	*get_next_line(int fd)
{
	int			t;
	char		*gnl;
	char		*temp;
	char		*baf;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	baf = malloc(BUFFER_SIZE + 1);
	if (!baf)
		return (NULL);
	t = BUFFER_SIZE;
	while (t > 0 && !ft_strchr(stock, '\n'))
	{
		t = read(fd, baf, BUFFER_SIZE);
		if (t <= 0)
			break ;
		baf[t] = '\0';
		temp = ft_strjoin(stock, baf);
		free(stock);
		stock = temp;
	}
	gnl = stop_at_nel(stock);
	stock = stock_str(stock);
	return (free(baf), gnl);
}
