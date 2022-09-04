/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:53:35 by sryou             #+#    #+#             */
/*   Updated: 2022/03/19 11:46:50 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_idx_st(char const *s1, char const *set)
{
	size_t	idx;

	idx = 0;
	while (s1[idx])
	{
		if (!ft_strchr(set, s1[idx]))
			break ;
		idx++;
	}
	return (idx);
}

static size_t	get_idx_ed(char const *s1, char const *set)
{
	size_t	idx;

	idx = ft_strlen(s1);
	while (1)
	{
		if (!ft_strchr(set, s1[idx]))
			break ;
		if (idx == 0)
			break ;
		idx--;
	}
	return (idx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	ed;
	char	*mkstr;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	st = get_idx_st(s1, set);
	ed = get_idx_ed(s1, set);
	if (st > ed)
		return (ft_strdup("\0"));
	mkstr = (char *)malloc(sizeof(char) * (ed - st + 2));
	if (mkstr == 0)
		return (0);
	ft_strlcpy(mkstr, s1 + st, ed - st + 2);
	return (mkstr);
}
