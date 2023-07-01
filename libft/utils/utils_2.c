/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:46:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/03 12:49:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "utils.h"

int	is_overflow_int_max(int x, int y)
{
	return (y > 0 && x >= INT_MAX - y);
}

int	get_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	get_hex_cnt(unsigned char *p, unsigned int sz)
{
	int	cnt;
	int	nxt;

	if (sz == 0)
		return (0);
	nxt = get_hex_cnt(p + 1, sz - 1);
	if (nxt > 0)
		return (nxt + 2);
	if ((*p) / 16 > 0)
		cnt = 2;
	else if ((*p) % 16 > 0)
		cnt = 1;
	else
		cnt = 0;
	return (cnt);
}

int	print_ptr(unsigned char *p, unsigned int sz, const char *base)
{
	int	cnt;

	if (sz == 0)
		return (0);
	cnt = print_ptr(p + 1, sz - 1, base);
	if (cnt == -1)
		return (-1);
	if (cnt > 0 || (*p) / 16 > 0)
	{
		if (print_char(base[(*p) / 16]) == -1)
			return (-1);
		++cnt;
	}
	if (cnt > 0 || (*p) % 16 > 0)
	{
		if (print_char(base[(*p) % 16]) == -1)
			return (-1);
		++cnt;
	}
	return (cnt);
}
