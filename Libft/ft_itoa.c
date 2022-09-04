/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:08:25 by sryou             #+#    #+#             */
/*   Updated: 2022/03/19 16:49:07 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoalen(int n)
{
	if (n > -10)
		return (1);
	return (1 + ft_itoalen(n / 10));
}

static void	ft_putnbr_in_str(char *str, int n, size_t len)
{
	str[len] = '\0';
	len--;
	while (1)
	{
		str[len] = '0' - (n % 10);
		n /= 10;
		if (len == 0)
			return ;
		len--;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*mkstr;

	if (n >= 0)
	{
		len = ft_itoalen(-n);
		mkstr = (char *)malloc(sizeof(char) * (len + 1));
	}
	else
	{
		len = ft_itoalen(n);
		mkstr = (char *)malloc(sizeof(char) * (len + 2));
	}
	if (mkstr == 0)
		return (0);
	mkstr[0] = '0';
	mkstr[1] = '\0';
	if (n > 0)
		ft_putnbr_in_str(mkstr, -n, len);
	else if (n < 0)
	{
		mkstr[0] = '-';
		ft_putnbr_in_str(mkstr + 1, n, len);
	}
	return (mkstr);
}
