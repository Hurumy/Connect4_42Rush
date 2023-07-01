/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:13:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/07/01 13:11:21 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opts.h"
#include "../libft.h"

static int	is_not_digit_dot(char c);

char	*ft_strnchr(const char *s, int c, int len)
{
	while (len > 0 && *s != (char)c && *s != '\0')
	{
		++s;
		--len;
	}
	if (len > 0 && *s == (char)c)
		return ((char *)s);
	return ((void *)0);
}

char	get_padding_char(const char *s, int len)
{
	while (len > 0)
	{
		if (*s == '0' && is_not_digit_dot(*(s - 1)))
			return ('0');
		++s;
		--len;
	}
	return (' ');
}

int	get_precision(const char *s, int len)
{
	int	precision;

	precision = -1;
	while (len > 0)
	{
		if (*s == '.')
			precision = ft_atoi(s + 1);
		++s;
		--len;
	}
	return (precision);
}

int	get_min_width(const char *s, int len)
{
	int	min_width;
	int	idx;

	idx = 0;
	min_width = 0;
	while (idx < len)
	{
		if (ft_isdigit(s[idx]) && s[idx] != '0')
			min_width = ft_atoi(s + idx);
		if ((s[idx] == '.') || (ft_isdigit(s[idx]) && s[idx] != '0'))
		{
			while (idx < len && !is_not_digit_dot(s[idx]))
				++idx;
		}
		else
			++idx;
	}
	return (min_width);
}

static int	is_not_digit_dot(char c)
{
	return (c != '.' && !ft_isdigit(c));
}
