/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:53:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/03 12:46:37 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../opts/opts.h"
#include "../utils/utils.h"

int	convert_ptr(t_opts *opts, void *p, int *crr_sz, int ret)
{
	int	prnt_sz;
	int	hex_cnt;
	int	w;

	opts_modify_for_nbr(opts);
	hex_cnt = get_hex_cnt((unsigned char *)&p, sizeof(p));
	w = 2 + get_max(opts->prc, hex_cnt);
	prnt_sz = get_max(opts->mnw, w);
	if (is_overflow_int_max(*crr_sz, prnt_sz))
		return (-1);
	if ((opts->lpd && opts->pdc == ' '
			&& print_nchars(opts->pdc, opts->mnw - w) == -1)
		|| (print_str("0x", 2) == -1)
		|| (opts->lpd && opts->pdc == '0'
			&& print_nchars(opts->pdc, opts->mnw - w) == -1)
		|| (print_nchars('0', opts->prc - hex_cnt) == -1)
		|| (print_ptr((unsigned char *)&p, sizeof(p), "0123456789abcdef") == -1)
		|| (!opts->lpd && print_nchars(opts->pdc, opts->mnw - w) == -1))
		return (-1);
	*crr_sz += prnt_sz;
	return (ret);
}
