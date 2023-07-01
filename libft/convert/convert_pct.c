/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:17:10 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/03 12:38:54 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../opts/opts.h"
#include "../utils/utils.h"
#include "convert.h"

int	convert_pct(t_opts *opts, int *crr_sz, int ret)
{
	return (convert_chr(opts, '%', crr_sz, ret));
}
