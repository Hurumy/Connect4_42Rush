/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:27:22 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 11:16:28 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

//choose line to put your pawn, then draw field
//the 3rd arg, take 1 or 2
/* ## RETURN VALUE ## */
//can not put, retry hearing -> 1
//can put -> 0 (then draw)
//another critical error -> -1 (sadly... session ends)
int	ft_add_pawn(t_info *t_maps, size_t x, int player)
{
	size_t	y;

	if (x < 1 || x > t_maps->col)
	{
		ft_printf(RED"You can NOT put to this line. CHOOSE ANOTHER ONE\n"RESET_COLOR);
		return (1);
	}
	if (t_maps->maps[1][x] != '0')
	{
		ft_printf(RED"This line is already filllled!!!!!!! CHOOSE ANOTHER ONE\n"RESET_COLOR);
		return (1);
	}
	y = 2;
	while (y < t_maps->row + 1)
	{
		if (t_maps->maps[y][x] == '0')
			y ++;
		if (t_maps->maps[y][x] != '0')
		{
			t_maps->maps[y - 1][x] = player + '0';
			break ;
		}
	}
	ft_draw_field(t_maps);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_info	t_maps;
// 	int		status;

// 	status = ft_init(argc, argv, &t_maps);
// 	if (status == -1)
// 		return (-1);
// 	ft_draw_field(&t_maps);
// 	ft_add_pawn(&t_maps, -1, 1);
// 	ft_exit(&t_maps);
// }
