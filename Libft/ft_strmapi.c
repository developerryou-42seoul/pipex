/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:22:21 by sryou             #+#    #+#             */
/*   Updated: 2022/03/11 21:31:45 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	idx;
	char	*mkstr;

	if (s == 0 || f == 0)
		return (0);
	len = ft_strlen(s);
	mkstr = (char *)malloc(sizeof(char) * (len + 1));
	if (mkstr == 0)
		return (0);
	idx = 0;
	while (idx < len)
	{
		mkstr[idx] = f(idx, s[idx]);
		idx++;
	}
	mkstr[idx] = '\0';
	return (mkstr);
}
