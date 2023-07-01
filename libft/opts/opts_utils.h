/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:39:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/02 17:39:00 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTS_UTILS_H
# define OPTS_UTILS_H

char	*ft_strnchr(const char *s, int c, int len);
int		has_zero(const char *s, int len);
char	get_padding_char(const char *s, int len);
int		get_precision(const char *s, int len);
int		get_min_width(const char *s, int len);

#endif
