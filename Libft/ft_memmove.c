/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:04:31 by sryou             #+#    #+#             */
/*   Updated: 2022/03/11 14:47:43 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	size_t			idx;

	if (!dst && !src)
		return (0);
	if (dst == src)
		return (dst);
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	idx = 0;
	if (dst < src)
		while (idx++ < len)
			str_dst[idx - 1] = str_src[idx - 1];
	else
		while (idx++ < len)
			str_dst[len - idx] = str_src[len - idx];
	return (dst);
}
