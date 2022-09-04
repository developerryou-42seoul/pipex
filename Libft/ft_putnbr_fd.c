/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:19:17 by sryou             #+#    #+#             */
/*   Updated: 2022/03/19 10:35:56 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_putnbr_fd(int n, int fd)
{
	if (n == 0)
		return ;
	recursive_putnbr_fd(n / 10, fd);
	ft_putchar_fd('0' - (n % 10), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n = -n;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		recursive_putnbr_fd(n, fd);
}
