/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:49:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/02/03 12:50:47 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int	print_char(char c);
int	print_nchars(char c, int n);
int	print_str(const char *s, int len);
int	get_dgt_cnt(unsigned int nbr, unsigned int base_size);
int	print_dgt(unsigned int nbr, const char *base, unsigned int base_size);
int	is_overflow_int_max(int x, int y);
int	get_max(int x, int y);
int	get_hex_cnt(unsigned char *p, unsigned int sz);
int	print_ptr(unsigned char *p, unsigned int sz, const char *base);

#endif
