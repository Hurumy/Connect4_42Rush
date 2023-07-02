/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:10:52 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 17:59:09 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

static void	ft_fill_with_null(t_info *t_maps)
{
	t_maps->col = 0;
	t_maps->row = 0;
	t_maps->maps = NULL;
	t_maps->first_move = 0;
	t_maps->winner = 0;
	t_maps->screen = NULL;
	t_maps->window = NULL;
	t_maps->tip_empty = NULL;
	t_maps->tip_player = NULL;
	t_maps->tip_cpu = NULL;
	t_maps->tip_cursor = NULL;
	t_maps->tip_base = NULL;
	t_maps->cursor = 0;
	t_maps->input_mode = 0;
}

//init, get infos, decide which one to play first
int	main(int argc, char **argv)
{
	int		status;
	t_info	t_maps;

	ft_fill_with_null(&t_maps);
	if (argc == 4)
	{
		main_libx(argc, argv);
		return (0);
	}
	status = ft_init(argc, argv, &t_maps);
	if (status == -1)
		return (ft_free(&t_maps));
	ft_randomly_choose_first_move(&t_maps);
	ft_draw_field(&t_maps);
	status = ft_get_move(&t_maps);
	if (status == -1)
		return (ft_free(&t_maps));
	ft_show_result(&t_maps);
	ft_exit(&t_maps);
	return (0);
}
