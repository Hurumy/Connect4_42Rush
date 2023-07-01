/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 09:12:19 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 10:12:08 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

int	ft_free_double_pointer(t_info *t_maps)
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

int	ft_free(t_info *t_maps)
{
	ft_free_double_pointer(t_maps);
	return (0);
}
