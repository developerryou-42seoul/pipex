/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:42:29 by sryou             #+#    #+#             */
/*   Updated: 2022/03/19 17:12:49 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	int		is_word;

	words = 0;
	is_word = 1;
	while (*s)
	{
		if (*s == c)
			is_word = 1;
		else
		{
			if (is_word)
				words++;
			is_word = 0;
		}
		s++;
	}
	return (words);
}

static char	*cut_word(char const *s, int len)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == 0)
		return (0);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static const char	*skip_str(char const *s, char c, size_t *len)
{
	*len = 0;
	while (*s == c)
		s++;
	while (s[*len] != c && s[*len] != 0)
		(*len)++;
	return (s);
}

static int	check_null(char **arr_words, size_t idx)
{
	size_t	idx_free;

	idx_free = 0;
	if (arr_words[idx] == 0)
	{
		while (idx_free < idx)
		{
			free(arr_words[idx]);
			idx_free++;
		}
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_words;
	size_t	count_words;
	size_t	idx;
	size_t	len;

	if (s == 0)
		return (0);
	count_words = ft_count_words(s, c);
	arr_words = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (arr_words == 0)
		return (0);
	idx = 0;
	while (idx < count_words)
	{
		s = skip_str(s, c, &len);
		arr_words[idx] = cut_word(s, len);
		if (check_null(arr_words, idx))
			return (0);
		idx++;
		s += len;
	}
	arr_words[idx] = 0;
	return (arr_words);
}
