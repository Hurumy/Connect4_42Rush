/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:50:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/03 12:47:10 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <stdarg.h>
# include "../opts/opts.h"

int	convert_chr(t_opts *opts, char c, int *crr_sz, int ret);
int	convert_str(t_opts *opts, const char *s, int *crr_sz, int ret);
int	convert_ptr(t_opts *opts, void *p, int *crr_sz, int ret);
int	convert_int(t_opts *opts, va_list *ap, int *crr_sz, int ret);
int	convert_pct(t_opts *opts, int *crr_sz, int ret);

#endif
