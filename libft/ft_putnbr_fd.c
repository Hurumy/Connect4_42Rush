/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:32:34 by taekklee          #+#    #+#             */
/*   Updated: 2023/03/02 21:27:50 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_helper(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_fd_helper(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_putnbr_fd_helper((unsigned int)n, fd);
	return ;
}
