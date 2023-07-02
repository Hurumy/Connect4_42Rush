/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:30:55 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 13:26:23 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

int	ft_show_result(t_info *t_maps)
{
	if (t_maps->winner == 1)
	{
		ft_printf(GREEN"\nPlayers WIN.\n\n"RESET_COLOR);
	}
	if (t_maps->winner == 2)
	{
		ft_printf(RED"\nCPUs WIN.\n\n"RESET_COLOR);
	}
	if (t_maps->winner == 3)
	{
		ft_printf(WHITE"\nDraw.\n\n"RESET_COLOR);
	}
	return (0);
}
