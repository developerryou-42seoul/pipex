/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:53:57 by sryou             #+#    #+#             */
/*   Updated: 2022/03/11 17:05:46 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch_c;

	ch_c = (char)c;
	while (*s)
	{
		if (*s == ch_c)
			return ((char *)s);
		s++;
	}
	if (*s == ch_c)
		return ((char *)s);
	return (0);
}
