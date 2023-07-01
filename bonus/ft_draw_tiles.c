/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_tiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:29:09 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 18:38:25 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_connect4.h"

int	ft_put_img(t_info *t_maps, char map, size_t x, size_t y)
{
	void	*tile;

	if (map == '0')
		tile = t_maps->tip_empty;
	else if (map == '1')
		tile = t_maps->tip_player;
	else if (map == '2')
		tile = t_maps->tip_cpu;
	else if (map == 'C')
		tile = t_maps->tip_cursor;
	else if (map == 'B')
		tile = t_maps->tip_base;
	else if (map == '\0')
		tile = t_maps->tip_base;
	else
	{
		return (-1);
	}
	mlx_put_image_to_window(t_maps->screen, t_maps->window, tile, 49 * (x - 1), 49 * y);
	return (0);
}

static int	ft_draw_tiles(t_info *t_maps)
{
	size_t	x;
	size_t	y;
	int		status;

	x = 1;
	y = 0;
	status = 0;
	while (y <= t_maps->row)
	{
		while (x <= t_maps->col)
		{
			status = ft_put_img(t_maps, t_maps->maps[y][x], x, y);
			if (status != 0)
				ft_error_with_free_libx(t_maps);
			x ++;
		}
		x = 1;
		y ++;
	}
	return (0);
}

int	ft_draw_field_libx(t_info *t_maps)
{
	int	status;

	status = ft_draw_tiles(t_maps);
	if (status == -1)
	{
		ft_error_with_free_libx(t_maps);
		return (-1);
	}
	return (0);
}
