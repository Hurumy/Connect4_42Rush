/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_libx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:56:53 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 16:41:38 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_connect4.h"

static int	ft_free_double_pointer_libx(t_info *t_maps)
{
	size_t	i;

	i = 0;
	if (t_maps->maps == NULL)
		return (0);
	while (i < t_maps->row + 2)
	{
		if (t_maps->maps[i] == NULL)
			break ;
		free(t_maps->maps[i]);
		i ++;
	}
	free (t_maps->maps);
	return (0);
}

int	ft_free_libx(t_info *t_maps)
{
	mlx_destroy_image(t_maps->screen, t_maps->tip_empty);
	mlx_destroy_image(t_maps->screen, t_maps->tip_player);
	mlx_destroy_image(t_maps->screen, t_maps->tip_cpu);
	mlx_destroy_image(t_maps->screen, t_maps->tip_cursor);
	mlx_destroy_window(t_maps->screen, t_maps->window);
	ft_free_double_pointer_libx(t_maps);
	return (0);
}
