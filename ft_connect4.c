/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:10:52 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 09:47:49 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

int	main(int argc, char **argv)
{
	int	status;
	t_info	t_maps;

	status = 0;
	//init, get infos, decide which one to play first
	status = ft_init(argc, argv, &t_maps);
	if (status == -1)
		return (-1);
	ft_draw_field(&t_maps);
	//while
		//draw
		//get_move
		//get_move - opponents
		//
	//is_game_ended
	//free,exit
	return (0);
}
