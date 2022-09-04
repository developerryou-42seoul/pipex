/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:47:53 by sryou             #+#    #+#             */
/*   Updated: 2022/03/19 11:28:31 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*mkstr;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mkstr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (mkstr == 0)
		return (0);
	mkstr[0] = '\0';
	ft_strlcat(mkstr, s1, len1 + 1);
	ft_strlcat(mkstr, s2, len1 + len2 + 1);
	return (mkstr);
}
