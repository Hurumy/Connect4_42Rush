/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libx_connect4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:40:19 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 16:43:11 by komatsud         ###   ########.fr       */
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
	ft_randomly_choose_first_move(&t_maps);
	ft_draw_field_libx(&t_maps);
	//mlx_hook(p_win->window, 2, 1L << 0, ft_set_keyhook, p_win);
	//mlx_hook(p_win->window, 17, 1L << 17, ft_set_mousehook, p_win);
	mlx_loop(t_maps.screen);
	return (0);
}
