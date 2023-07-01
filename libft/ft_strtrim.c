/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:17 by taekklee          #+#    #+#             */
/*   Updated: 2023/03/02 20:51:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char const *set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

static size_t	get_start(char const *s, char const *set)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && is_in(set, s[len]))
		++len;
	return (len);
}

static size_t	get_end(char const *s, char const *set)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0 && is_in(set, s[len - 1]))
		--len;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	start;
	size_t	end;

	if (set == NULL)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start > end)
		end = start;
	dst = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1 + start, end - start);
	return (dst);
}
