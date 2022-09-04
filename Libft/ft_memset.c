/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:26:18 by sryou             #+#    #+#             */
/*   Updated: 2022/03/11 14:47:53 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			idx;

	str = (unsigned char *)b;
	idx = 0;
	while (idx < len)
	{
		str[idx] = (unsigned char)c;
		idx++;
	}
	return (b);
}
