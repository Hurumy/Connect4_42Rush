/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:53:29 by taekklee          #+#    #+#             */
/*   Updated: 2023/07/01 13:10:46 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "convert/convert.h"
#include "libft.h"
#include "opts/opts.h"
#include "utils/utils.h"

static int	va_end_and_ret(va_list *ap, int ret);
static int	handle_conversion(const char *s, va_list *ap, int *crr_sz);
static int	get_format_size(
				const char *s, const char *valid_chars, const char *types);

int	ft_printf(const char *s, ...)
{
	int		len;
	int		jump;
	va_list	args;

	va_start(args, s);
	len = 0;
	while (*s != '\0')
	{
		if (*s == '%')
			jump = handle_conversion(s, &args, &len);
		else if (!is_overflow_int_max(len, 1))
		{
			jump = print_char(*s);
			++len;
		}
		else
			jump = -1;
		if (jump == -1)
			return (va_end_and_ret(&args, -1));
		s += jump;
	}
	return (va_end_and_ret(&args, len));
}

static int	va_end_and_ret(va_list *ap, int ret)
{
	va_end(*ap);
	return (ret);
}

static int	handle_conversion(const char *s, va_list *ap, int *crr_sz)
{
	int		fmt_sz;
	t_opts	opts;

	opts_set_default_vals(&opts);
	fmt_sz = get_format_size(s, "-0.# +123456789cspdiuxX%", "cspdiuxX%");
	if (fmt_sz == 1 || !ft_strchr("cspdiuxX%", *(s + fmt_sz - 1)))
		return (fmt_sz);
	opts_set(&opts, s, fmt_sz);
	if (opts_is_type(&opts, "%"))
		return (convert_pct(&opts, crr_sz, fmt_sz));
	else if (opts_is_type(&opts, "c"))
		return (convert_chr(&opts, va_arg(*ap, int), crr_sz, fmt_sz));
	else if (opts_is_type(&opts, "s"))
		return (convert_str(&opts, va_arg(*ap, const char *), crr_sz, fmt_sz));
	else if (opts_is_type(&opts, "p"))
		return (convert_ptr(&opts, va_arg(*ap, void *), crr_sz, fmt_sz));
	else if (opts_is_type(&opts, "diuxX"))
		return (convert_int(&opts, ap, crr_sz, fmt_sz));
	return (fmt_sz);
}

static int	get_format_size(
	const char *s, const char *valid_chars, const char *types)
{
	char	*type_found;
	int		fmt_sz;

	fmt_sz = 1;
	++s;
	while (*s != '\0' && ft_strchr(valid_chars, *s))
	{
		type_found = ft_strchr(types, *s);
		++fmt_sz;
		++s;
		if (type_found)
			break ;
	}
	return (fmt_sz);
}
