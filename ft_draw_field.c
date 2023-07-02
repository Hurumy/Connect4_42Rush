/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 09:45:03 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 11:45:50 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

//fix later
int	ft_draw_field(t_info *t_maps)
{
	size_t	y;
	size_t	x;
	size_t	i;

	y = 1;
	x = 1;
	ft_printf("\n");
	while (x <= t_maps->col)
	{
		if (x <= 9)
			ft_printf(" ");
		ft_printf("%d", x);
		x ++;
	}
	ft_printf("\n");
	while (y < t_maps->row + 1)
	{
		x = 1;
		i = 1;
		while (i < t_maps->col + 1)
		{
			ft_printf("－");
			i ++;
		}
		ft_printf("\n");
		while (x < t_maps->col + 1)
		{
			ft_printf(GREY"|"RESET_COLOR);
			if (t_maps->maps[y][x] == '0')
				ft_printf(" ");
			else if (t_maps->maps[y][x] == '1')
				ft_printf(GREEN"●"RESET_COLOR);
			else if (t_maps->maps[y][x] == '2')
				ft_printf(RED"◆"RESET_COLOR);
			x ++;
		}
		ft_printf(GREY"|"RESET_COLOR);
		ft_printf("\n");
		y ++;
	}
	i = 1;
	while (i < t_maps->col + 1)
	{
		ft_printf("－");
		i ++;
	}
	ft_printf("\n\n");
	return (0);
}
