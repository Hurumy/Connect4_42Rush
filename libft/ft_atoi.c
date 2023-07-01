/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:40:59 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/21 19:57:19 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

static void	trim_leading_spaces(const char **pstr)
{
	while (is_space(**pstr))
		++(*pstr);
	return ;
}

static int	get_is_positive(const char **pstr)
{
	if ((**pstr == '+' || **pstr == '-') && *((*pstr)++) == '-')
		return (0);
	return (1);
}

static long	get_long(const char *str, long limit)
{
	unsigned long	val;

	val = 0;
	while (ft_isdigit(*str))
	{
		if (((unsigned long)limit - (*str - '0')) / 10 < val)
			return (limit);
		val = val * 10 + (*str - '0');
		++str;
	}
	if ((long)val == limit)
		return (limit);
	if (limit < 0)
		return (-(long)val);
	return ((long)val);
}

int	ft_atoi(const char *str)
{
	trim_leading_spaces(&str);
	if (get_is_positive(&str))
		return ((int)get_long(str, LONG_MAX));
	return ((int)get_long(str, LONG_MIN));
}
