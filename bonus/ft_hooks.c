/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:43:37 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 09:59:38 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_connect4.h"

static int	ft_set_keyhook_gameend(int keycode, t_info *t_maps);

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
	static int	turn_number = 1;

	status = 1;
	if (t_maps->first_move == CPU_MOVE && turn_number == 0)
		turn_number ++;
	while (status == 1)
	{
		ft_printf(CYAN"\nTurn %u.\nPlayers turn.\n"RESET_COLOR, turn_number);
		if (t_maps->input_mode == 0)
		{
			status = ft_add_pawn(t_maps, t_maps->cursor, PLAYER_MOVE + 1);
			if (status == 0)
			{
				turn_number ++;
				ft_draw_field_libx(t_maps);
				status = ft_is_game_ended(t_maps, turn_number, t_maps->cursor);
				if (status == -1)
					return (-1);
				else if (status == 1 || status == 2)
				{
					if (status == 1)
						mlx_string_put(t_maps->screen, t_maps->window, t_maps->col * 49 / 2, t_maps->row * 49 / 2, 0xFF00, "You win!!");
					else if (status == 2)
						mlx_string_put(t_maps->screen, t_maps->window, t_maps->col * 49 / 2, t_maps->row * 49 / 2, 0xFF00, "Draw.");
					mlx_string_put(t_maps->screen, t_maps->window, t_maps->col * 49 / 2, (t_maps->row + 1) * 49 / 2, 0xFF00, "Press S to exit");
					mlx_hook(t_maps->window, 02, 1L << 0, ft_set_keyhook_gameend, (void *)t_maps);
					mlx_loop(t_maps->screen);
					return (0);
				}
				break ;
			}
			else if (status == 1)
			{
				mlx_hook(t_maps->window, 02, 1L << 0, ft_set_keyhook, (void *)t_maps);
				mlx_loop(t_maps->screen);
			}
			t_maps->input_mode = 0;
		}
		else if (t_maps->input_mode != 0)
		{
			ft_printf(CYAN"Please input from the shell this turn\n\n"RESET_COLOR);
			where_to_put = ft_move_by_player();
			status = ft_add_pawn(t_maps, where_to_put, PLAYER_MOVE + 1);
			if (status == 0)
			{
				turn_number ++;
				t_maps->input_mode = 0;
				ft_draw_field_libx(t_maps);
				status = ft_is_game_ended(t_maps, turn_number, t_maps->cursor);
				if (status == -1)
					return (-1);
				else if (status == 1 || status == 2)
				{
					if (status == 1)
						mlx_string_put(t_maps->screen, t_maps->window, t_maps->col * 49 / 2, t_maps->row * 49 / 2, 0xFF00, "You win!!");
					else if (status == 2)
						mlx_string_put(t_maps->screen, t_maps->window, t_maps->col * 49 / 2, t_maps->row * 49 / 2, 0xFF00, "Draw.");
					mlx_string_put(t_maps->screen, t_maps->window, t_maps->col * 49 / 2, (t_maps->row + 1) * 49 / 2, 0xFF00, "Press S to exit");
					mlx_hook(t_maps->window, 02, 1L << 0, ft_set_keyhook_gameend, (void *)t_maps);
					mlx_loop(t_maps->screen);
					return (0);
				}
				break ;
			}
			else if (status == 1)
			{
				t_maps->input_mode = 0;
				mlx_hook(t_maps->window, 02, 1L << 0, ft_set_keyhook, (void *)t_maps);
				mlx_loop(t_maps->screen);
			}
		}
	}
	status = 1;
	while (status == 1)
	{
		ft_printf(CYAN"Turn %u.\nCPUs turn.\n"RESET_COLOR, turn_number);
		where_to_put = 1 + rand() % (t_maps->col);
		status = ft_add_pawn(t_maps, where_to_put, CPU_MOVE + 1);
		if (status == 0)
		{
			turn_number ++;
			ft_draw_field_libx(t_maps);
			status = ft_is_game_ended(t_maps, turn_number, where_to_put);
			if (status == -1)
			{
				return (-1);
			}
			else if (status == 1 || status == 2)
			{
				if (status == 1)
				{
					mlx_string_put(t_maps->screen, t_maps->window, t_maps->col * 49 / 2, t_maps->row * 49 / 2, 0xFF00, "CPU win!!");
				}
				else if (status == 2)
				{
					mlx_string_put(t_maps->screen, t_maps->window, t_maps->col * 49 / 2, t_maps->row * 49 / 2, 0xFF00, "Draw.");
				}
				mlx_string_put(t_maps->screen, t_maps->window, t_maps->col * 49 / 2, (t_maps->row + 1) * 49 / 2, 0xFF00, "Press S to exit");
				mlx_hook(t_maps->window, 02, 1L << 0, ft_set_keyhook_gameend, (void *)t_maps);
				mlx_loop(t_maps->screen);
				return (0);
			}
			break ;
		}
	}
	return (0);
}

static int	ft_set_keyhook_gameend(int keycode, t_info *t_maps)
{
	if (keycode == S_KEY)
	{
		ft_free_libx(t_maps);
		ft_show_result(t_maps);
		exit(EXIT_SUCCESS);
		return (0);	
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
	else if (keycode == F_KEY)
	{
		if (t_maps->input_mode == 0)
		{
			t_maps->input_mode = 1;
			ft_printf("change input mode this turn. Press S key on the window.\n");
		}
	}
	return (0);
}
