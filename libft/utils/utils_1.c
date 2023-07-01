/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:46:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/02 18:33:30 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_char(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	print_nchars(char c, int n)
{
	while (n > 0)
	{
		if (print_char(c) == -1)
			return (-1);
		--n;
	}
	return (0);
}

int	print_str(const char *s, int len)
{
	return (write(STDOUT_FILENO, s, len));
}

int	print_dgt(unsigned int nbr, const char *base, unsigned int base_size)
{
	if (nbr == 0)
		return (0);
	if ((print_dgt(nbr / base_size, base, base_size) == -1)
		|| (print_char(base[nbr % base_size]) == -1))
		return (-1);
	return (0);
}

int	get_dgt_cnt(unsigned int nbr, unsigned int base_size)
{
	if (nbr == 0)
		return (0);
	return (get_dgt_cnt(nbr / base_size, base_size) + 1);
}
