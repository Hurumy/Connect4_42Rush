/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:10:52 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 11:31:49 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_connect4.h"

//init, get infos, decide which one to play first
int	main(int argc, char **argv)
{
	int		status;
	t_info	t_maps;

	status = ft_init(argc, argv, &t_maps);
	if (status == -1)
		return (-1);
	ft_randomly_choose_first_move(&t_maps);
	ft_draw_field(&t_maps);
	status = ft_get_move(&t_maps);
	if (status == -1)
		return (-1);
	//ft_show_result -> show result
	if (status == -1)
		return (-1);
	ft_exit(&t_maps);
	return (0);
}
