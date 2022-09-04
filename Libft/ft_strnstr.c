/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:23:23 by sryou             #+#    #+#             */
/*   Updated: 2022/03/11 17:06:07 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		idx = 0;
		while (haystack[idx] == needle[idx] && idx < len)
		{
			idx++;
			if (needle[idx] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
