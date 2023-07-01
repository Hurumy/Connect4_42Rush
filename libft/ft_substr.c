/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:05:02 by taekklee          #+#    #+#             */
/*   Updated: 2023/03/02 21:05:31 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*dst;

	len_s = ft_strlen(s);
	if (start < len_s)
		len = get_min(len, len_s - start);
	else
		len = 0;
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s + start, len);
	return (dst);
}
