/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_game_ended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:40:11 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 12:26:53 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

static int	ft_search_4cnct(t_info *t_maps, int x)
{
	size_t	y;

	if (x < 1 || x > (int)t_maps->col)
		return (-1);
	if (t_maps->maps[1][x] != '0')
		return (-1);
	y = 1;
	while (y < t_maps->row + 1)
	{
		if (t_maps->maps[y][x] == '0')
			y ++;
		if (t_maps->maps[y][x] != '0')
			break ;
	}
	return (0);
}

//RETURN VALUE
//-1 -> clitical error session will be ended
//0 -> game is not ended
//1 -> game is ended, set t_maps->winner (1 or 2)
//2 -> game is ended, but its a draw
int	ft_is_game_ended(t_info *t_maps, int turn_number, int where_to_put)
{
	int	status;

	status = ft_search_4cnct(t_maps, where_to_put);
	if (status == -1)
	{
		ft_error_with_free(t_maps);
		return (-1);
	}
	else if (status == 1)
		return (1);
	if (turn_number > (int)(t_maps->col * t_maps->row))
		return (2);
	return (0);
}
