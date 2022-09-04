/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:58:09 by sryou             #+#    #+#             */
/*   Updated: 2022/05/14 13:56:02 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	size_t			idx;

	if (!dst && !src)
		return (0);
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		str_dst[idx] = str_src[idx];
		idx++;
	}
	return (dst);
}
