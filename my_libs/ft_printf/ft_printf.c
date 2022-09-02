/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:20:37 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/25 18:44:09 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_spcif(const char *fmt, va_list args, t_flags *flags, t_str s)
{
	int	count;

	count = 0;
	if (*fmt == 's')
		count += print_str(va_arg(args, char *), flags, *fmt, s);
	else if (*fmt == 'c')
		count += print_char(va_arg(args, int), flags, *fmt, s);
	else if ((*fmt == 'd') || (*fmt == 'i'))
		count += print_int(va_arg(args, int), flags, 'd', s);
	else if (*fmt == 'u')
		count += print_unsigned_int(va_arg(args, int), flags, *fmt, s);
	else if ((*fmt == 'x') || (*fmt == 'X'))
		count += print_hex(va_arg(args, int), flags, *fmt, s);
	else if (*fmt == 'p')
		count += print_void_hex(va_arg(args, void *), flags, *fmt, s);
	else if (*fmt == '%')
		count += print_percentage(*fmt, s);
	else
	{
		write(1, "%", 1);
		count += 2;
	}
	return (count);
}

static int	check_flags(const char *format, t_flags *flags)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	while (ft_strchr(" +#", format[index]))
	{
		if (*format == '+' || *format == ' ' || *format == '#')
		{
			is_true_flags(&format, flags);
			i++;
			format++;
		}	
		else
			index++;
	}
	return (i + 1);
}

int	ft_printf(const char *format, ...)
{
	va_list		list_arg;
	int			counter;
	t_flags		flags;
	t_str		s;

	flags = init_flags();
	s = init_tstr();
	va_start(list_arg, format);
	counter = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write (1, format, 1);
			counter += 1;
		}
		else if ((*format == '%') && *format)
		{
			format += check_flags(format + 1, &flags);
			counter += check_spcif(format, list_arg, &flags, s);
		}
		format++;
	}
	va_end(list_arg);
	return (counter);
}
