/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:05:06 by sryou             #+#    #+#             */
/*   Updated: 2022/05/14 13:56:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	idx = 0;
	while (*src != '\0' && idx + 1 < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		idx++;
	}
	*dst = '\0';
	return (len);
}
