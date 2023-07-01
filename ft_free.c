/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 09:12:19 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 09:27:03 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

int	ft_free_double_pointer(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return (0);
	while (1)
	{
		if (map[i] == NULL)
			break ;
		free(map[i]);
		i ++;
	}
	free (map);
	return (0);
}


int	ft_free(t_info *t_maps)
{
	ft_free_double_pointer(t_maps->maps);
	return (0);
}
