/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libx_connect4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:40:19 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 17:13:44 by taekklee         ###   ########.fr       */
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
	t_maps.input_mode = 0;
	ft_randomly_choose_first_move(&t_maps);
	status = 1;
	while (t_maps.first_move == CPU_MOVE && status == 1)
	{
		ft_printf(CYAN"\nTurn 1.\nCPUs turn.\n"RESET_COLOR);
		status = ft_add_pawn(&t_maps, ft_move_by_cpu(&t_maps, 1, CPU_MOVE), CPU_MOVE);
		if (status != 1)
		{
			status = ft_draw_field_libx(&t_maps);
			if (status == -1)
				return (-1);
			else if (status == 0)
				break ;
		}
	}
	status = ft_draw_field_libx(&t_maps);
	if (status == -1)
		return (-1);
	mlx_hook(t_maps.window, 02, 1L << 0, ft_set_keyhook, (void *)&t_maps);
	mlx_loop(t_maps.screen);
	return (0);
}
