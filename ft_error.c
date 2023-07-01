/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:38:36 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 09:54:37 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

void	ft_error(void)
{
	printf("Error\n");
}

void	ft_error_with_free(t_info *t_maps)
{
	ft_free(t_maps);
	printf("Error\n");
	return ;
}
