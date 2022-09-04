/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:36:58 by sryou             #+#    #+#             */
/*   Updated: 2022/03/19 17:26:46 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*mkstr;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	if (size > len + start)
		size = len;
	else if (size >= start)
		size = size - start;
	else
		size = 0;
	mkstr = (char *)malloc(sizeof(char) * (size + 1));
	if (mkstr == 0)
		return (0);
	ft_strlcpy(mkstr, s + start, size + 1);
	return (mkstr);
}
