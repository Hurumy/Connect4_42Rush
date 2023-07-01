/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:13:35 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 12:25:28 by komatsud         ###   ########.fr       */
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
		}
		status = ft_add_pawn(t_maps, where_to_put, in_turn % 2 + 1);
		if (status == 0)
		{
			in_turn ++;
			turn_number ++;
			status = ft_is_game_ended(t_maps, turn_number, where_to_put);
			if (status == -1)
				return (-1);
			else if (status == 1 || status == 2)
				break ;
		}
		else if (status == 1)
			status = 0;
	}
	return (0);
}
