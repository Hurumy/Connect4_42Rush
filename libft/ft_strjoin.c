/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:10:34 by taekklee          #+#    #+#             */
/*   Updated: 2023/03/02 21:19:13 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dst;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1, len1);
	ft_memcpy(dst + len1, s2, len2);
	return (dst);
}
