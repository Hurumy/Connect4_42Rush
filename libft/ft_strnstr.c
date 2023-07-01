/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:10:34 by taekklee          #+#    #+#             */
/*   Updated: 2023/01/16 12:15:06 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	while (len > 0 && *haystack != '\0')
	{
		if (len_needle <= len && ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
