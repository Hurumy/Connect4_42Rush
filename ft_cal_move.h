/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_move.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:05:48 by taekklee          #+#    #+#             */
/*   Updated: 2023/07/02 15:38:58 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAL_MOVE_H
# define FT_CAL_MOVE_H

# define MAX_DEPTH (2)
# define RANGE (7)
# define TARGET_LEN (4)

# define TRUE (1)
# define FALSE (0)

typedef struct s_board{
	char	**map;
	int		*null_cnt;
	int		*cand_arr;
	size_t	cand_sz;
	size_t	h;
	size_t	w;
}			t_board;

int	ft_cal_move(t_info *t_maps, int move);

#endif
