/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_libx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:56:53 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 20:02:18 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_connect4.h"

int	ft_free_libx(t_info *t_maps)
{
	if (t_maps->tip_empty != NULL)
		mlx_destroy_image(t_maps->screen, t_maps->tip_empty);
	if (t_maps->tip_player != NULL)
		mlx_destroy_image(t_maps->screen, t_maps->tip_player);
	if (t_maps->tip_cpu != NULL)
		mlx_destroy_image(t_maps->screen, t_maps->tip_cpu);
	if (t_maps->tip_cursor != NULL)
		mlx_destroy_image(t_maps->screen, t_maps->tip_cursor);
	if (t_maps->tip_base != NULL)
		mlx_destroy_image(t_maps->screen, t_maps->tip_base);
	if (t_maps->window != NULL)
		mlx_destroy_window(t_maps->screen, t_maps->window);
	ft_free_double_pointer(t_maps);
	return (0);
}
