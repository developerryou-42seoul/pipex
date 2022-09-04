/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:53:57 by sryou             #+#    #+#             */
/*   Updated: 2022/03/11 17:33:40 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch_c;
	size_t			idx;

	str = (unsigned char *)s;
	ch_c = (unsigned char)c;
	idx = 0;
	while (idx < n)
	{
		if (str[idx] == ch_c)
			return ((void *)(str + idx));
		idx++;
	}
	return (0);
}
