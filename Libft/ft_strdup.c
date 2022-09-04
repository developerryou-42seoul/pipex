/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:58:11 by sryou             #+#    #+#             */
/*   Updated: 2022/03/11 17:23:44 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mkstr;
	int		len;

	len = ft_strlen(s1);
	mkstr = (char *)malloc(sizeof(char) * (len + 1));
	if (mkstr == 0)
		return (0);
	ft_strlcpy(mkstr, s1, len + 1);
	return (mkstr);
}
