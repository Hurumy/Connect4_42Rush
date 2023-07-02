/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmove_libx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:39:34 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 16:44:59 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_connect4.h"

int	ft_get_move_libx(t_info *t_maps)
{
	int		status;
	size_t	turn_number;
	int		move;

	turn_number = 1;
	status = 0;
	move = t_maps->first_move;
	while (status == 0)
	{
		if (move == PLAYER_MOVE)
		{
			ft_printf(CYAN"Turn %u.\nPlayers turn.\n"RESET_COLOR, turn_number);
		}
		else if (move == CPU_MOVE)
		{
			ft_printf(CYAN"Turn %u.\nCPUs turn.\n"RESET_COLOR, turn_number);
			status = ft_add_pawn(t_maps, ft_move_by_cpu(t_maps, 1, move), move);
			ft_draw_field_libx(t_maps);
		}
	}
	return (0);
}
