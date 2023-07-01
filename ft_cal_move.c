/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:38:02 by taekklee          #+#    #+#             */
/*   Updated: 2023/07/01 22:45:15 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"
#include "ft_cal_move.h"

static int	ft_init_board(t_board *brd, t_info *t_maps);
static int	ft_eval_board(t_board *brd, char player, size_t depth, size_t left, size_t right);
static int	ft_is_over(t_board *brd, char c);
static void	ft_cal_null_cnt(t_board *brd);
static char	**ft_copy_map(char **strs, size_t h, size_t w);
static int	ft_free_board(t_board *brd, int ret);

int	ft_cal_move(t_info *t_maps, int move)
{
	int		num;
	t_board	brd;

	dprintf(2, "cal_move");
	if (ft_init_board(&brd, t_maps) == -1)
		return (-1);
	num = ft_eval_board(&brd, move + '0', MAX_DEPTH, 1, t_maps->col);
	dprintf(2, "num : %d\n", num);
	for(size_t j = 0; j < brd.w; ++j)
		dprintf(2, "%d ", brd.null_cnt[j]);
	dprintf(2, "\n");

	return (ft_free_board(&brd, num));
}

static int	ft_init_board(t_board *brd, t_info *t_maps)
{
	brd->h = t_maps->row + 2;
	brd->w = t_maps->col + 2;
	brd->map = ft_copy_map(t_maps->maps, brd->h, brd->w);
	brd->null_cnt = (int *)ft_calloc(brd->w, sizeof(int));
	if (brd->map == NULL || brd->null_cnt == NULL)
		return (ft_free_board(brd, -1));
	ft_cal_null_cnt(brd);
	return (0);
}

static int	ft_eval_board(t_board *brd, char player, size_t depth, size_t left, size_t right)
{
	size_t	j;
	int		ret;
	int		cand;

	if (ft_is_over(brd, player == '1' ? '2' : '1'))
		return (-1);
	if (depth == 0)
		return (0);
	cand = 0;
	j = left;
	while (j <= right)
	{
		ret = 0;
		if (brd->null_cnt[j] > 0)
		{
			brd->map[brd->null_cnt[j]][j] = player;
			--(brd->null_cnt[j]);
			ret = ft_eval_board(brd, player == '1' ? '2' : '1', depth - 1, j - RANGE > 0 ? j - RANGE : 1, j + RANGE < brd->w ? j + RANGE : brd->w - 1);
			brd->map[brd->null_cnt[j]][j] = '0';
			++(brd->null_cnt[j]);
			if (ret == -1)
				return (j);
			if (ret > 0)
			{
				if (cand > 0)
					return (-1);
				cand = j;
			}
		}
		++j;
	}
	return (cand);
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
			if (c == brd->map[i][j] && ++cnt >= TARGET_LEN)
				return (TRUE);
			else
				cnt = 0;
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
			if (c == brd->map[i][j] && ++cnt >= TARGET_LEN)
				return (TRUE);
			else
				cnt = 0;
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
			if (c == brd->map[i][j] && ++cnt >= TARGET_LEN)
				return (TRUE);
			else
				cnt = 0;
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
			if (c == brd->map[i][j] && ++cnt >= TARGET_LEN)
				return (TRUE);
			else
				cnt = 0;
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
	return (ret);
}
