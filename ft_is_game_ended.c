/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_game_ended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:40:11 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 17:24:25 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

static int	ft_search_4cnct(t_info *t_maps, int x)
{
	size_t	y;
	size_t	p;
	size_t	q;
	int		i;
	char	pawn;

	if (x < 1 || x > (int)t_maps->col)
		return (0);
	y = 1;
	while (y <= t_maps->row)
	{
		if (t_maps->maps[y][x] == '0')
			y ++;
		if (t_maps->maps[y][x] != '0')
		{
			pawn = t_maps->maps[y][x];
			break ;
		}
	}
	p = y;
	q = x;
	i = 0;
	while (1) // down
	{
		if (p > t_maps->row || t_maps->maps[p][q] != pawn)
		{
			p = y;
			break ;
		}
		else if (t_maps->maps[p][q] == pawn)
		{
			p ++;
			i ++;
			if (i >= 4)
			{
				t_maps->winner = pawn - '0';
				return (1);
			}
		}
	}
	i = 0;
	while (1) // right
	{
		if (q > t_maps->col || t_maps->maps[p][q] != pawn)
		{
			q = x;
			break ;
		}
		q ++;
		i ++;
		if (i >= 4)
		{
			t_maps->winner = pawn - '0';
			return (1);
		}
	}
	while (1) // left
	{
		if (q < 1 || t_maps->maps[p][q] != pawn)
		{
			q = x;
			break ;
		}
		q --;
		i ++;
		if (i >= 5)
		{
			t_maps->winner = pawn - '0';
			return (1);
		}
	}
	i = 0;
	while (1) // right upper
	{
		if (q > t_maps->col || p < 1 || t_maps->maps[p][q] != pawn)
		{
			q = x;
			p = y;
			break ;
		}
		q ++;
		p --;
		i ++;
		if (i >= 4)
		{
			t_maps->winner = pawn - '0';
			return (1);
		}
	}
	while (1) // left downer
	{
		if (q < 1 || p > t_maps->row || t_maps->maps[p][q] != pawn)
		{
			q = x;
			p = y;
			break ;
		}
		q --;
		p ++;
		i ++;
		if (i >= 5)
		{
			t_maps->winner = pawn - '0';
			return (1);
		}
	}
	i = 0;
	while (1) // right downer
	{
		if (q > t_maps->col || p > t_maps->row || t_maps->maps[p][q] != pawn)
		{
			q = x;
			p = y;
			break ;
		}
		q ++;
		p ++;
		i ++;
		if (i >= 4)
		{
			t_maps->winner = pawn - '0';
			return (1);
		}
	}
	while (1) // left upper
	{
		if (q < 1 || p < 1 || t_maps->maps[p][q] != pawn)
		{
			q = x;
			p = y;
			break ;
		}
		q --;
		p --;
		i ++;
		if (i >= 5)
		{
			t_maps->winner = pawn - '0';
			return (1);
		}
	}
	return (0);
}

//RETURN VALUE
//-1 -> clitical error session will be ended
//0 -> game is not ended
//1 -> game is ended, set t_maps->winner (1 or 2)
//2 -> game is ended, but its a draw, set t_maps->winner = 3
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
	{
		t_maps->winner = 3;
		return (2);
	}
	return (0);
}
