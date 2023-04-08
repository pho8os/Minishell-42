/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:26:20 by absaid            #+#    #+#             */
/*   Updated: 2023/04/08 06:20:50 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	(nb < 0) && ((write(fd, "-", 1), nb *= -1));
	(nb > 9) && (ft_putnbr_fd(nb / 10, fd), n += 0);
	write(fd, &"0123456789"[nb % 10], 1);
}
