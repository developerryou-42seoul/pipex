/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:41:20 by sryou             #+#    #+#             */
/*   Updated: 2022/05/14 13:56:22 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize == 0)
		return (src_len);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	idx = dst_len;
	dst = dst + dst_len;
	while (*src != '\0' && idx + 1 < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		idx++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
