/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:10:52 by komatsud          #+#    #+#             */
/*   Updated: 2023/06/30 21:45:02 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

int	main(int argc, char **argv)
{
	int	status;

	status = 0;
	//init, get infos, decide which one to play first
	status = ft_init(argc, argv);
	if (status == -1)
		return (-1);
	//while
		//draw
		//get_move
		//get_move - opponents
		//
	//is_game_ended
	//free,exit
	return (0);
}
