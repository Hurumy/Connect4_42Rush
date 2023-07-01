/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:35:57 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/03 12:39:54 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../opts/opts.h"
#include "../utils/utils.h"

static int	strnlen_int(const char *s, int n);

int	convert_str(t_opts *opts, const char *s, int *crr_sz, int ret)
{
	int	prnt_sz;
	int	w;

	if (!s)
		s = "(null)";
	if (opts->prc >= 0)
		w = strnlen_int(s, opts->prc);
	else
		w = strnlen_int(s, INT_MAX);
	prnt_sz = get_max(opts->mnw, w);
	if (is_overflow_int_max(*crr_sz, prnt_sz))
		return (-1);
	if ((opts->lpd && print_nchars(opts->pdc, opts->mnw - w) == -1)
		|| (print_str(s, w) == -1)
		|| (!opts->lpd && print_nchars(opts->pdc, opts->mnw - w) == -1))
		return (-1);
	*crr_sz += prnt_sz;
	return (ret);
}

static int	strnlen_int(const char *s, int n)
{
	int	len;

	len = 0;
	while (len < n && *s != '\0')
	{
		++len;
		++s;
	}
	return (len);
}
