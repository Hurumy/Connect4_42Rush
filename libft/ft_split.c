/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/22 16:49:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_str(char **strs, char const *s, size_t len)
{
	*strs = (char *)ft_calloc(len + 1, sizeof(char));
	if (*strs == NULL)
		return (-1);
	ft_memcpy(*strs, s, len);
	return (0);
}

static size_t	count_splits(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			++s;
		if (*s == '\0')
			break ;
		++cnt;
		while (*s != '\0' && *s != c)
			++s;
	}
	return (cnt);
}

static int	make_splits(char **strs, const char *s, char c)
{
	size_t	len;

	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			++s;
		if (*s == '\0')
			break ;
		len = 0;
		while (s[len] != '\0' && s[len] != c)
			++len;
		if (set_str(strs, s, len) == -1)
			return (-1);
		s += len;
		++strs;
	}
	return (0);
}

static void	*free_splits(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		++i;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	strs = (char **)ft_calloc(count_splits(s, c) + 1, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	if (make_splits(strs, s, c) == -1)
		return (free_splits(strs));
	return (strs);
}
