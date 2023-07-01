/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:13:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/07/01 13:11:11 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opts.h"
#include "opts_utils.h"
#include "../libft.h"

void	opts_set_default_vals(t_opts *opts)
{
	opts->nsn = 0;
	opts->psn = '\0';
	opts->lpd = 1;
	opts->pdc = ' ';
	opts->mnw = 0;
	opts->prc = -1;
	opts->typ = '\0';
	return ;
}

void	opts_set(t_opts *opts, const char *s, int len)
{
	if (ft_strnchr(s, '#', len))
		opts->nsn = 1;
	if (ft_strnchr(s, '+', len))
		opts->psn = '+';
	else if (ft_strnchr(s, ' ', len))
		opts->psn = ' ';
	if (ft_strnchr(s, '-', len))
		opts->lpd = 0;
	else
		opts->pdc = get_padding_char(s, len);
	opts->mnw = get_min_width(s, len);
	opts->prc = get_precision(s, len);
	opts->typ = *(s + len - 1);
	return ;
}

int	opts_is_type(t_opts *opts, const char *types)
{
	return (ft_strchr(types, opts->typ) != (void *)0);
}

void	opts_modify_for_nbr(t_opts *opts)
{
	if (opts->prc == -1)
		opts->prc = 1;
	else
		opts->pdc = ' ';
	return ;
}
