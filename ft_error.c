/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:38:36 by komatsud          #+#    #+#             */
/*   Updated: 2023/06/30 21:44:00 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

void	ft_error_invalidargs(void)
{
	ft_printf("Error\n");
}

void	ft_error_with_free()
{
	ft_free();
	ft_printf("Error\n");
	return ;
}
