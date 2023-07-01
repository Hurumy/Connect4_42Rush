/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:34 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/02 16:05:44 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTS_H
# define OPTS_H

typedef struct s_opts
{
	int		nsn;
	char	psn;
	int		lpd;
	char	pdc;
	int		mnw;
	int		prc;
	char	typ;
}			t_opts;

void	opts_set_default_vals(t_opts *opts);
void	opts_set(t_opts *opts, const char *s, int len);
int		opts_is_type(t_opts *opts, const char *types);
void	opts_modify_for_nbr(t_opts *opts);

#endif
