/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:39:45 by taekklee          #+#    #+#             */
/*   Updated: 2023/03/02 20:59:19 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len_helper(unsigned int n)
{
	if (n >= 10)
		return (get_len_helper(n / 10) + 1);
	return (1);
}

static size_t	get_len(int n)
{
	size_t	is_minus;

	is_minus = 0;
	if (n < 0)
	{
		is_minus = 1;
		n = -n;
	}
	return (get_len_helper((unsigned int)n) + is_minus);
}

static char	*set_nbr_helper(char *s, unsigned int n)
{
	if (n >= 10)
		s = set_nbr_helper(s, n / 10);
	*s = '0' + (n % 10);
	return (s + 1);
}

static void	set_nbr(char *s, int n)
{
	if (n < 0)
	{
		*(s++) = '-';
		n = -n;
	}
	set_nbr_helper(s, (unsigned int)n);
	return ;
}

char	*ft_itoa(int n)
{
	char	*s;

	s = (char *)ft_calloc(get_len(n) + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	set_nbr(s, n);
	return (s);
}
