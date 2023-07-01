/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 09:45:03 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 11:27:33 by komatsud         ###   ########.fr       */
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
	printf("\n");
	while (y < t_maps->row + 1)
	{
		x = 1;
		i = 1;
		while (i < t_maps->col + 1)
		{
			printf("－");
			i ++;
		}
		printf("\n");
		while (x < t_maps->col + 1)
		{
			printf(GREY"|"RESET_COLOR);
			if (t_maps->maps[y][x] == '0')
				printf(" ");
			else if (t_maps->maps[y][x] == '1')
				printf(GREEN"●"RESET_COLOR);
			else if (t_maps->maps[y][x] == '2')
				printf(RED"◆"RESET_COLOR);
			x ++;
		}
		printf(GREY"|"RESET_COLOR);
		printf("\n");
		y ++;
	}
	i = 1;
	while (i < t_maps->col + 1)
	{
		printf("－");
		i ++;
	}
	printf("\n\n");
	return (0);
}
