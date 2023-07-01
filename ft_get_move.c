/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:13:35 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 11:36:22 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

//row, column, player or AI
int	ft_get_move(t_info *t_maps)
{
	int		status;
	size_t	turn_number;
	size_t	in_turn;
	int		where_to_put;

	turn_number = 1;
	status = 0;
	in_turn = t_maps->first_move;
	while (status == 0)
	{
		if (in_turn % 2 == 1)
		{
			printf(CYAN"Turn %ld.\nPlayers turn.\n"RESET_COLOR, turn_number);
			where_to_put = 4;
		}
		if (in_turn % 2 == 0)
		{
			printf(CYAN"Turn %ld.\nCPUs turn.\n"RESET_COLOR, turn_number);
			where_to_put = 4;
			status = 1;
		}
		status = ft_add_pawn(t_maps, where_to_put, in_turn % 2 + 1);
		if (status == -1)
		{
			ft_error_with_free(t_maps);
			return (-1);
		}
		if (status == 0)
		{
			in_turn ++;
			turn_number ++;
		}
		if (status == 1)
			status = 0;
		//ft_is_game_ended -> field all filled or someone make connect4
	}
	t_maps->result = 1;
	return (0);
}
