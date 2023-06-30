/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:31:47 by komatsud          #+#    #+#             */
/*   Updated: 2023/06/30 21:50:05 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

static int	ft_is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (0);
	return (-1);
}

static int	ft_is_positive_num(char *str)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (status == 0 && str != NULL && str[i] != '\0')
	{
		status = ft_is_num(str[i]);
		i ++;
	}
	if (status == -1)
		return (-1);
	return (0);
}

static int	ft_atoi_rewrite(char *str)
{
	int		i;
	size_t	num;

	while (str[i] != NULL)
	{
		num = num * 10 + str[i] - '0';
		if (num >= INT_MAX)
			return (-1);
	}
}

int	ft_arg_to_number(int argc, char *argv)
{
	int		status;
	size_t	law;
	size_t	col;

	status = 0;
	if (argc != 3)
		return (-1);
	status = ft_is_positive_num(argv[1]);
	if (status == -1)
		return (-1);
	status = ft_is_positive_num(argv[2]);
	if (status == -1)
		return (-1);
}

int	ft_init(int argc, int argv)
{
	
}
