/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:02:11 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/03 12:38:43 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../opts/opts.h"
#include "../utils/utils.h"

static int	convert_sgn_base10(t_opts *opts, int val, int *crr_sz);
static int	convert_usgn_base10(t_opts *opts, unsigned int uval, int *crr_sz);
static int	convert_usgn_base16(t_opts *opts, unsigned int uval, int *crr_sz);

int	convert_int(t_opts *opts, va_list *ap, int *crr_sz, int ret)
{
	int	prnt_sz;

	opts_modify_for_nbr(opts);
	prnt_sz = -1;
	if (opts_is_type(opts, "di"))
		prnt_sz = convert_sgn_base10(opts, va_arg(*ap, int), crr_sz);
	else if (opts_is_type(opts, "u"))
		prnt_sz = convert_usgn_base10(opts, va_arg(*ap, unsigned int), crr_sz);
	else if (opts_is_type(opts, "xX"))
		prnt_sz = convert_usgn_base16(opts, va_arg(*ap, unsigned int), crr_sz);
	if (prnt_sz == -1)
		return (-1);
	*crr_sz += prnt_sz;
	return (ret);
}

static int	convert_sgn_base10(t_opts *opts, int val, int *crr_sz)
{
	unsigned int	uval;	
	int				dgt_cnt;
	int				w;

	uval = (unsigned int)val;
	if (val < 0)
		uval = -uval;
	dgt_cnt = get_dgt_cnt(uval, 10);
	w = (val < 0 || opts->psn != '\0') + get_max(opts->prc, dgt_cnt);
	if (is_overflow_int_max(*crr_sz, get_max(opts->mnw, w)))
		return (-1);
	if ((opts->lpd && opts->pdc == ' '
			&& print_nchars(opts->pdc, opts->mnw - w) == -1)
		|| (val < 0 && print_char('-') == -1)
		|| (val >= 0 && opts->psn != '\0' && print_char(opts->psn) == -1)
		|| (opts->lpd && opts->pdc == '0'
			&& print_nchars(opts->pdc, opts->mnw - w) == -1)
		|| (print_nchars('0', opts->prc - dgt_cnt) == -1)
		|| (print_dgt(uval, "0123456789", 10) == -1)
		|| (!opts->lpd && print_nchars(opts->pdc, opts->mnw - w) == -1))
		return (-1);
	return (get_max(opts->mnw, w));
}

static int	convert_usgn_base10(t_opts *opts, unsigned int uval, int *crr_sz)
{
	int	dgt_cnt;
	int	w;

	dgt_cnt = get_dgt_cnt(uval, 10);
	w = get_max(opts->prc, dgt_cnt);
	if (is_overflow_int_max(*crr_sz, get_max(opts->mnw, w)))
		return (-1);
	if ((opts->lpd && print_nchars(opts->pdc, opts->mnw - w) == -1)
		|| (print_nchars('0', opts->prc - dgt_cnt) == -1)
		|| (print_dgt(uval, "0123456789", 10) == -1)
		|| (!opts->lpd && print_nchars(opts->pdc, opts->mnw - w) == -1))
		return (-1);
	return (get_max(opts->mnw, w));
}

static int	convert_usgn_base16(t_opts *opts, unsigned int uval, int *crr_sz)
{
	int	dgt_cnt;
	int	w;

	dgt_cnt = get_dgt_cnt(uval, 16);
	w = get_max(opts->prc, dgt_cnt);
	if (uval > 0 && opts->nsn)
		w += 2;
	if (is_overflow_int_max(*crr_sz, get_max(opts->mnw, w)))
		return (-1);
	if ((opts->lpd && opts->pdc == ' '
			&& print_nchars(opts->pdc, opts->mnw - w) == -1)
		|| (uval > 0 && opts->nsn && opts->typ == 'x'
			&& print_str("0x", 2) == -1)
		|| (uval > 0 && opts->nsn && opts->typ == 'X'
			&& print_str("0X", 2) == -1)
		|| (opts->lpd && opts->pdc == '0'
			&& print_nchars(opts->pdc, opts->mnw - w) == -1)
		|| (print_nchars('0', opts->prc - dgt_cnt) == -1)
		|| (opts->typ == 'x' && print_dgt(uval, "0123456789abcdef", 16) == -1)
		|| (opts->typ == 'X' && print_dgt(uval, "0123456789ABCDEF", 16) == -1)
		|| (!opts->lpd && print_nchars(opts->pdc, opts->mnw - w) == -1))
		return (-1);
	return (get_max(opts->mnw, w));
}
