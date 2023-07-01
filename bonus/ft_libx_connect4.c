/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libx_connect4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:40:19 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 19:02:58 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_connect4.h"

int	main_libx(int argc, char **argv)
{
	int		status;
	t_info	t_maps;

	status = ft_init_libx(argc, argv, &t_maps);
	if (status == -1)
		return (-1);
	t_maps.cursor = 1;
	ft_randomly_choose_first_move(&t_maps);
	if (t_maps.first_move == CPU_MOVE)
	{
		status = ft_add_pawn(&t_maps, 1, CPU_MOVE + 1);
		ft_draw_field_libx(&t_maps);
	}
	ft_draw_field_libx(&t_maps);
	mlx_hook(t_maps.window, 02, 1L << 0, ft_set_keyhook, (void *)&t_maps);
	//mlx_loop_hook(t_maps.window, ft_get_move_libx, (void *)&t_maps);
	mlx_loop(t_maps.screen);
	return (0);
}
