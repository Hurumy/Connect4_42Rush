/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:31:47 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 22:19:07 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

int	ft_is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (0);
	return (-1);
}

int	ft_is_positive_num(char *str)
{
	int	i;
	int	status;

	if (str == NULL || *str == '\0')
		return (-1);
	i = 0;
	status = 0;
	while (status == 0 && str[i] != '\0')
	{
		status = ft_is_num(str[i]);
		i ++;
	}
	if (status == -1)
	{
		ft_error();
		return (-1);
	}
	return (0);
}

int	ft_atoi_rewrite(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (num > (INT_MAX / 2 - (str[i] - '0')) / 10)
		{
			return (-1);
		}
		num = num * 10 + str[i] - '0';
		i ++;
	}
	return (num);
}

int	ft_arg_to_number(int argc, char **argv, t_info *t_maps)
{
	int		status;

	status = 0;
	if (argc != 3)
		return (-1);
	status = ft_is_positive_num(argv[1]);
	if (status == -1)
		return (-1);
	status = ft_is_positive_num(argv[2]);
	if (status == -1)
		return (-1);
	status = ft_atoi_rewrite(argv[1]);
	if (status == -1)
		return (-1);
	t_maps->row = status;
	status = ft_atoi_rewrite(argv[2]);
	if (status == -1)
		return (-1);
	t_maps->col = status;
	return (0);
}

int	ft_init_map_row(t_info *t_maps, size_t y)
{
	size_t	x;
	int		mode;

	x = 0;
	mode = 0;
	if (y == 0 || y == t_maps->row + 1)
		mode = 1;
	while (x < t_maps->col + 2)
	{
		t_maps->maps[y][x] = '0';
		if (mode == 1 || x == 0 || x == t_maps->col + 1)
			t_maps->maps[y][x] = '\0';
		x ++;
	}
	return (0);
}

int	ft_malloc_maps(t_info *t_maps)
{
	size_t	i;

	i = 0;
	t_maps->maps = malloc(sizeof(char *) * (t_maps->row + 2));
	if (t_maps->maps == NULL)
	{
		ft_error();
		return (-1);
	}
	while (i < t_maps->row + 2)
	{
		t_maps->maps[i] = malloc(sizeof(char) * (t_maps->col + 2));
		if (t_maps->maps[i] == NULL)
		{
			ft_free_double_pointer(t_maps);
			ft_error();
			return (-1);
		}
		ft_init_map_row(t_maps, i);
		i ++;
	}
	return (0);
}

//convert arg into number
//check args validity
//malloc maps
//init maps
int	ft_init(int argc, char **argv, t_info *t_maps)
{
	int	status;

	ft_printf(GREY"\nInitializing system ...\n"RESET_COLOR);
	status = ft_arg_to_number(argc, argv, t_maps);
	if (status == -1)
	{
		ft_error();
		return (-1);
	}
	if (t_maps->col < 7 || t_maps->row < 6 || t_maps->col > 30 || t_maps->row > 30)
	{
		ft_error();
		return (-1);
	}
	status = ft_malloc_maps(t_maps);
	if (status == -1)
		return (-1);
	ft_printf(GREY"Successfully Completed. Game Start.\n\n"RESET_COLOR);
	return (0);
}
