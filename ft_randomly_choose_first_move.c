/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randomly_choose_first_move.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:57:43 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 15:18:15 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

int	ft_randomly_choose_first_move(t_info *t_maps)
{
	srand((unsigned int)time(NULL));
	t_maps->first_move = rand() % 2;
	if (t_maps->first_move == PLAYER_MOVE)
		ft_printf(CYAN"Player moves first.\n"RESET_COLOR);
	if (t_maps->first_move == CPU_MOVE)
		ft_printf(CYAN"CPU moves first.\n"RESET_COLOR);
	return (0);
}
