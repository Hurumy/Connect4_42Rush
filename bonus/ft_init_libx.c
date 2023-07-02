/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_libx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:46:54 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 13:23:39 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_connect4.h"

static int	ft_load_maptiles(t_info *t_maps)
{
	int	n = 49;

	t_maps->tip_cursor = mlx_png_file_to_image(t_maps->screen, "bonus/tiles/cursor.png", &n, &n);
	t_maps->tip_empty = mlx_png_file_to_image(t_maps->screen, "bonus/tiles/empty.png", &n, &n);
	t_maps->tip_player = mlx_png_file_to_image(t_maps->screen, "bonus/tiles/player.png", &n, &n);
	t_maps->tip_cpu = mlx_png_file_to_image(t_maps->screen, "bonus/tiles/cpu.png", &n, &n);
	t_maps->tip_base = mlx_png_file_to_image(t_maps->screen, "bonus/tiles/base.png", &n, &n);
	if (!t_maps->tip_cursor || !t_maps->tip_empty || !t_maps->tip_player || !t_maps->tip_cpu || !t_maps->tip_base)
	{
		ft_error_with_free_libx(t_maps);
		return (-1);
	}
	return (0);
}

int	ft_arg_to_number_libx(int argc, char **argv, t_info *t_maps)
{
	int		status;

	status = 0;
	if (argc != 4)
		return (-1);
	status = ft_is_positive_num(argv[1]);
	if (status == -1)
		return (-1);
	status = ft_is_positive_num(argv[2]);
	if (status == -1)
		return (-1);
	t_maps->row = ft_atoi_rewrite(argv[1]);
	t_maps->col = ft_atoi_rewrite(argv[2]);
	return (0);
}

int	ft_init_map_row_libx(t_info *t_maps, size_t y)
{
	size_t	x;
	int		mode;

	x = 0;
	mode = 0;
	if (y == 0 || y == t_maps->row + 1)
		mode = 1;
	while (x < t_maps->col + 2)
	{
		t_maps->maps[y][x] = '0';
		if (mode == 1 || x == 0 || x == t_maps->col + 1)
			t_maps->maps[y][x] = '\0';
		x ++;
	}
	return (0);
}

int	ft_malloc_maps_libx(t_info *t_maps)
{
	size_t	i;

	i = 0;
	t_maps->maps = malloc(sizeof(char *) * (t_maps->row + 2));
	if (t_maps->maps == NULL)
	{
		ft_error();
		return (-1);
	}
	while (i < t_maps->row + 2)
	{
		t_maps->maps[i] = malloc(sizeof(char) * (t_maps->col + 2));
		if (t_maps->maps[i] == NULL)
		{
			ft_free_double_pointer(t_maps);
			ft_error();
			return (-1);
		}
		ft_init_map_row_libx(t_maps, i);
		i ++;
	}
	return (0);
}


int	ft_init_libx(int argc, char **argv, t_info *t_maps)
{
	int	status;

	ft_printf(GREY"\nLIBX: Initializing system ...\n"RESET_COLOR);
	status = ft_arg_to_number_libx(argc, argv, t_maps);
	if (status == -1)
	{
		ft_error();
		return (-1);
	}
	if (t_maps->col < 7 || t_maps->row < 6 || t_maps->col > 30 || t_maps->row > 30)
	{
		ft_error();
		return (-1);
	}
	t_maps->screen = mlx_init();
	if (t_maps->screen == NULL)
	{
		ft_error();
		return (-1);
	}
	status = ft_load_maptiles(t_maps);
	if (status == -1)
	{
		ft_error_with_free_libx(t_maps);
		return (-1);
	}
	status = ft_malloc_maps_libx(t_maps);
	if (status == -1)
		return (-1);
	t_maps->window = mlx_new_window(t_maps->screen, 49 * (int)t_maps->col, 49 * ((int)t_maps->row + 1), "42_CONNECT_4");
	if (t_maps->window == NULL)
	{
		ft_error_with_free_libx(t_maps);
		return (-1);
	}
	ft_printf(GREY"LIBX: Successfully Completed. Game Start.\n\n"RESET_COLOR);
	return (0);
}
