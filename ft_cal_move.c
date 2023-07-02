/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:38:02 by taekklee          #+#    #+#             */
/*   Updated: 2023/07/02 18:45:34 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"
#include "ft_cal_move.h"

static int	ft_init_board(t_board *brd, t_info *t_maps);
static int	ft_eval_board(t_board *brd, char player, int depth, int left, int right);
static int	ft_is_over(t_board *brd, char c);
static void	ft_cal_null_cnt(t_board *brd);
static char	**ft_copy_map(char **strs, size_t h, size_t w);
static int	ft_free_board(t_board *brd, int ret);

int	ft_cal_move(t_info *t_maps, int move)
{
	t_board	brd;

	if (ft_init_board(&brd, t_maps) == -1)
		return (-1);
	char player = move + '0';
	char opp_player = (CPU_MOVE + PLAYER_MOVE - move) + '0';
	int num = 0;
	int left = 1, right = (int)t_maps->col;
	for (int eval, j = left; j <= right; ++j)
	{
		if (brd.null_cnt[j] == 0)
			continue;
		brd.map[brd.null_cnt[j]][j] = player;
		--(brd.null_cnt[j]);
		eval = ft_eval_board(&brd, opp_player, brd.depth, left, right);
		++(brd.null_cnt[j]);
		brd.map[brd.null_cnt[j]][j] = '0';
		if (eval == -1)
		{
			num = j;
			break ;
		}
		if (eval == 0)
			brd.cand_arr[brd.cand_sz++] = j;
	}
	if (num == 0)
		num = brd.cand_sz == 0 ?
			1 + rand() % t_maps->col :
			brd.cand_arr[rand() % brd.cand_sz];
	return (ft_free_board(&brd, num));
}

static int	ft_init_board(t_board *brd, t_info *t_maps)
{
	if (t_maps->row <= 7 && t_maps->col <= 7)
		brd->depth = HIGH_DEPTH;
	else if (t_maps->row <= 10 && t_maps->col <= 10)
		brd->depth = MID_DEPTH;
	else
		brd->depth = LOW_DEPTH;
	brd->h = t_maps->row + 2;
	brd->w = t_maps->col + 2;
	brd->cand_sz = 0;
	brd->map = ft_copy_map(t_maps->maps, brd->h, brd->w);
	brd->null_cnt = (int *)ft_calloc(brd->w, sizeof(int));
	brd->cand_arr = (int *)ft_calloc(brd->w, sizeof(int));
	if (brd->map == NULL || brd->null_cnt == NULL || brd->cand_arr == NULL)
		return (ft_free_board(brd, -1));
	ft_cal_null_cnt(brd);
	return (0);
}

static int	ft_eval_board(t_board *brd, char player, int depth, int left, int right)
{
	if (ft_is_over(brd, player == '1' ? '2' : '1'))
		return (-1);
	if (depth == 0)
		return (0);
	int cand_cnt = 0, cand_all = 0;
	for (int eval, j = left; j <= right; ++j)
	{
		if (brd->null_cnt[j] == 0)
			continue;
		brd->map[brd->null_cnt[j]][j] = player;
		--(brd->null_cnt[j]);
		eval = ft_eval_board(brd, player == '1' ? '2' : '1', depth - 1, left, right);
		++(brd->null_cnt[j]);
		brd->map[brd->null_cnt[j]][j] = '0';
		if (eval == -1)
			return (1);
		cand_cnt += eval;
		++cand_all;
	}
	if (cand_cnt == cand_all)
		return (-1);
	return (0);
}

static int	ft_is_over(t_board *brd, char c)
{
	int	i;
	int	j;
	int	cnt;
	int	h = brd->h - 2;
	int	w = brd->w - 2;

	i = 1;
	while (i <= h)
	{
		cnt = 0;
		j = 1;
		while (j <= w)
		{
			if (c == brd->map[i][j])
				++cnt;
			else
				cnt = 0;
			if (cnt == TARGET_LEN)
				return (TRUE);
			++j;
		}
		++i;
	}

	j = 1;
	while (j <= w)
	{
		cnt = 0;
		i = 1;
		while (i <= h)
		{
			if (c == brd->map[i][j])
				++cnt;
			else
				cnt = 0;
			if (cnt == TARGET_LEN)
				return (TRUE);
			++i;
		}
		++j;
	}

	for(int d = 1 - h; d <= w - 1; ++d)
	{
		cnt = 0;
		if (d > 0)
			i = 1, j = 1 + d;
	 	else
			i = 1 - d, j = 1;
		for(;i <= h && j <= w; ++i, ++j)
		{
			if (c == brd->map[i][j])
				++cnt;
			else
				cnt = 0;
			if (cnt == TARGET_LEN)
				return (TRUE);
		}
	}

	for(unsigned int d = 2; d <= (unsigned int)h + w; ++d)
	{
		cnt = 0;
		if (d <= (unsigned int)1 + w)
			i = 1, j = d - 1;
	 	else
			i = d - w, j = w;
		for(;i <= h && j >= 1; ++i, --j)
		{
			if (c == brd->map[i][j])
				++cnt;
			else
				cnt = 0;
			if (cnt == TARGET_LEN)
				return (TRUE);
		}
	}
	return (FALSE);
}

static void	ft_cal_null_cnt(t_board *brd)
{
	size_t	cnt;
	size_t	j;

	j = 1;
	while (j <= brd->w - 2)
	{
		cnt = 1;
		while (cnt < brd->h && brd->map[cnt][j] == '0')
			++cnt;
		brd->null_cnt[j] = cnt - 1;
		++j;
	}
}

static char	**ft_copy_map(char **strs, size_t h, size_t w)
{
	char	**dst;
	size_t	i;

	dst = (char **)ft_calloc(h, sizeof(char *));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < h)
	{
		dst[i] = (char *)ft_calloc(w, sizeof(char));
		if (dst[i] == NULL)
			return (NULL);
		ft_memcpy(dst[i], strs[i], w);
		++i;
	}
	return (dst);
}

static int	ft_free_board(t_board *brd, int ret)
{
	size_t	i;

	if (brd->map != NULL)
	{
		i = 0;
		while (i < brd->h)
		{
			if (brd->map[i] == NULL)
				break;
			free(brd->map[i]);
			++i;
		}
		free(brd->map);
	}
	if (brd->null_cnt != NULL)
		free(brd->null_cnt);
	if (brd->cand_arr != NULL)
		free(brd->cand_arr);
	return (ret);
}
