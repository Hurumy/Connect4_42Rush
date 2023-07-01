/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:18:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/03 12:36:06 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../opts/opts.h"
#include "../utils/utils.h"

int	convert_chr(t_opts *opts, char c, int *crr_sz, int ret)
{
	int	prnt_sz;
	int	w;

	w = 1;
	prnt_sz = get_max(opts->mnw, w);
	if (is_overflow_int_max(*crr_sz, prnt_sz))
		return (-1);
	if ((opts->lpd && print_nchars(opts->pdc, opts->mnw - w) == -1)
		|| (print_char(c) == -1)
		|| (!opts->lpd && print_nchars(opts->pdc, opts->mnw - w) == -1))
		return (-1);
	*crr_sz += prnt_sz;
	return (ret);
}
