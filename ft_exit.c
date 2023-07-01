/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:02:42 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 10:06:13 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

int	ft_exit(t_info *t_maps)
{
	ft_free(t_maps);
	printf(GREEN"GOOD BYE.\n"RESET_COLOR);
	return (0);
}
