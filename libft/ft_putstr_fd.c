/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:27:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/06/06 09:16:43 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	ssize_t	written_bytes;

	len = ft_strlen(s);
	while (len > 0)
	{
		written_bytes = write(fd, s, len);
		if (written_bytes == -1)
			break ;
		len -= written_bytes;
	}
	return ;
}
