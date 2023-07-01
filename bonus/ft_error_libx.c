/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_libx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:55:48 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 16:24:14 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_connect4.h"

void	ft_error_with_free_libx(t_info *t_maps)
{
	ft_free_libx(t_maps);
	ft_printf("Error\n");
	return ;
}
