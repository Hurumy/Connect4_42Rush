/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 09:45:03 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 09:57:27 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

//fix later
int	ft_draw_field(t_info *t_maps)
{
	int	y;

	y = 1;
	while (y < (int)t_maps->row + 2)
	{
		printf("%s\n", t_maps->maps[y] + 1);
		y ++;
	}
	return (0);
}
