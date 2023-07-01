/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:20:34 by taekklee          #+#    #+#             */
/*   Updated: 2023/01/18 18:53:17 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	backward_copy(void *dst, const void *src, size_t len)
{
	unsigned char		*s;
	const unsigned char	*t;

	s = (unsigned char *)dst + len;
	t = (const unsigned char *)src + len;
	while (len > 0)
	{
		--s;
		--t;
		--len;
		*s = *t;
	}
	return ;
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
		backward_copy(dst, src, len);
	return (dst);
}
