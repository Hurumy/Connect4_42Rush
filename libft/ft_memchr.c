/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:46:32 by taekklee          #+#    #+#             */
/*   Updated: 2023/03/02 21:31:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;

	us = (const unsigned char *)s;
	while (n > 0 && *us != (unsigned char)c)
	{
		++us;
		--n;
	}
	if (n == 0)
		return (NULL);
	return ((void *)us);
}
