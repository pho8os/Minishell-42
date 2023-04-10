/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 06:05:44 by absaid            #+#    #+#             */
/*   Updated: 2023/04/10 05:49:48 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	fd_printf(int fd, const char *fmt, ...)
{
	int		i;
	va_list	s;

	i = -1;
	va_start(s, fmt);
	while (fmt[++i])
	{
		(fmt[i] != '%') && (i += 0, write(fd, &fmt[i], 1));
		if (fmt[i] == '%' && fmt[i + 1])
		{
			if (fmt[i + 1] == 's')
				ft_putstr_fd(va_arg(s, char *), fd);
			else if (fmt[i + 1] == 'd')
				ft_putnbr_fd(va_arg(s, int), fd);
			else
				write(fd, &fmt[i + 1], 1);
			i++;
		}
	}
}
