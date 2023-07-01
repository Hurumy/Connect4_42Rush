/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:10:52 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 11:25:32 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

//init, get infos, decide which one to play first
int	main(int argc, char **argv)
{
	int		status;
	size_t	in_turn;
	size_t	turn_number;
	size_t	where_to_put;
	t_info	t_maps;

	status = ft_init(argc, argv, &t_maps);
	if (status == -1)
		return (-1);
	ft_randomly_choose_first_move(&t_maps);
	in_turn = t_maps.first_move;
	turn_number = 1;
	while (status == 0)
	{
		ft_draw_field(&t_maps);
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
		ft_add_pawn(&t_maps, where_to_put, in_turn % 2 + 1);
		in_turn ++;
		turn_number ++;
		//ft_is_game_ended -> field all filled or someone make connect4
	}
	//ft_show_result -> show result
	if (status == -1)
		return (-1);
	ft_exit(&t_maps);
	return (0);
}
