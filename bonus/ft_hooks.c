/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:43:37 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 19:35:32 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_connect4.h"

int	ft_move_left(t_info *t_maps)
{
	if (t_maps->cursor == 1)
		return (0);
	else
		ft_put_img(t_maps, 'B', t_maps->cursor, 0);
	t_maps->cursor -= 1;
	ft_put_img(t_maps, 'C', t_maps->cursor, 0);
	return (0);
}

int	ft_move_right(t_info *t_maps)
{
	if (t_maps->cursor == (int)t_maps->col)
		return (0);
	else
		ft_put_img(t_maps, 'B', t_maps->cursor, 0);
	t_maps->cursor += 1;
	ft_put_img(t_maps, 'C', t_maps->cursor, 0);
	return (0);
}

int	ft_decide(t_info *t_maps)
{
	int			where_to_put;
	int			status;
	static int	turn_number = 0;

	status = 1;
	if (t_maps->first_move == CPU_MOVE && turn_number == 0)
		turn_number ++;
	while (status == 1)
	{
		turn_number ++;
		status = ft_add_pawn(t_maps, t_maps->cursor, PLAYER_MOVE + 1);
		if (status == 0)
		{
			ft_draw_field_libx(t_maps);
			status = ft_is_game_ended(t_maps, turn_number, t_maps->cursor);
			if (status == -1)
				return (-1);
			else if (status == 1 || status == 2)
			{
				ft_free_libx(t_maps);
				ft_show_result(t_maps);
				exit(0);
				return (0);
			}
			break ;
		}
	}
	status = 1;
	while (status == 1)
	{
		turn_number ++;
		where_to_put = 1 + rand() % (t_maps->col);
		status = ft_add_pawn(t_maps, where_to_put, CPU_MOVE + 1);
		if (status == 0)
		{
			ft_draw_field_libx(t_maps);
			status = ft_is_game_ended(t_maps, turn_number, where_to_put);
			if (status == -1)
				return (-1);
			else if (status == 1 || status == 2)
			{
				ft_free_libx(t_maps);
				ft_show_result(t_maps);
				exit(0);
				return (0);
			}
			break ;
		}
	}
	return (0);
}

int	ft_set_keyhook(int keycode, t_info *t_maps)
{
	if (keycode == A_KEY)
		ft_move_left(t_maps);
	else if (keycode == D_KEY)
		ft_move_right(t_maps);
	else if (keycode == S_KEY)
		ft_decide(t_maps);
	return (0);
}
