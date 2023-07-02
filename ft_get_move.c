/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:13:35 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 16:12:21 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"
#include "get_next_line.h"
#include "ft_cal_move.h"

static char	*ft_trim_str(char *line, const char *set);
static int	ft_extract_number(char *line);

int	ft_get_move(t_info *t_maps)
{
	int		status;
	size_t	turn_number;
	int		move;
	int		where_to_put;

	turn_number = 1;
	status = 0;
	move = t_maps->first_move;
	while (status == 0)
	{
		if (move == PLAYER_MOVE)
		{
			ft_printf(CYAN"Turn %u.\nPlayers turn.\n"RESET_COLOR, turn_number);
			where_to_put = ft_move_by_player();
		}
		else
		{
			ft_printf(CYAN"Turn %u.\nCPUs turn.\n"RESET_COLOR, turn_number);
			where_to_put = ft_move_by_cpu(t_maps, turn_number, move);
		}
		if (where_to_put == -1)
			return (-1);
		status = ft_add_pawn(t_maps, where_to_put, move);
		if (status == 0)
		{
			move = (move == PLAYER_MOVE ? CPU_MOVE : PLAYER_MOVE);
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

static char	*ft_trim_str(char *line, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(line);
	while (j > 0 && ft_strchr(set, line[j - 1]) != NULL)
		++j;
	while (i < j && ft_strchr(set, line[i]) != NULL)
		++i;
	line[j] = '\0';
	return (line + i);
}

static int	ft_extract_number(char *line)
{
	line = ft_trim_str(line, " \t");
	if (ft_is_positive_num(line) == -1)
		return (-1);
	return (ft_atoi_rewrite(line));
}

int	ft_move_by_player(void)
{
	char	*line;
	int		num;
	int		is_newline;

	line = get_next_line(STDIN_FILENO, &is_newline);
	if (line == NULL)
		return (-1);
	num = ft_extract_number(line);
	free(line);
	return (num == -1 ? 0 : num);
}

int	ft_move_by_cpu(t_info *t_maps, int turn_cnt, int move)
{
	int	num;

	if (turn_cnt == 1)
		return ((t_maps->col + 1) / 2);
	num = ft_cal_move(t_maps, move);
	if (1 <= num && num <= (int)t_maps->col)
		return (num);
	return (1 + rand() % t_maps->col);
}
