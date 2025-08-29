/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:50:46 by thfernan          #+#    #+#             */
/*   Updated: 2025/08/28 20:31:56 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_check_int(t_list *spec, int n)
{
	int	total_len;
	int	zeros;
	int	padding;
	int	fill_char;

	total_len = 0;
	zeros = ft_calc_zeros(n, spec);
	padding = ft_calc_padding(n, spec, zeros);
	fill_char = ft_get_fill_char(spec);
	if (!spec->minus && fill_char == ' ')
		total_len += ft_padding(fill_char, padding);
	if ((n != 0 || spec->dot < 0) && (n < 0 || spec->plus || spec->space))
		total_len += ft_putsign(n, spec);
	if (!spec->minus && fill_char == '0')
		total_len += ft_padding(fill_char, padding);
	total_len += ft_putzeros(zeros);
	if (!(n == 0 && spec->dot == 0))
		total_len += ft_putnbr_signed(ft_nbr_abs(n));
	if (spec->minus)
		total_len += ft_padding(' ', padding);
	return (total_len);
}

int	ft_check_unsigned(t_list *spec, unsigned int n)
{
	int	zeros;
	int	total_len;
	int	fill_char;
	int	padding;

	total_len = 0;
	zeros = ft_calc_zeros_unsigned(n, spec);
	padding = ft_calc_padding_unsigned(n, spec, zeros);
	fill_char = ft_get_fill_char(spec);
	if (!spec->minus && fill_char == ' ')
		total_len += ft_padding(fill_char, padding);
	if (!spec->minus && fill_char == '0')
		total_len += ft_padding(fill_char, padding);
	total_len += ft_putzeros(zeros);
	if (!(n == 0 && spec->dot == 0))
		total_len += ft_putnbr_unsigned(n);
	if (spec->minus)
		total_len += ft_padding(' ', padding);
	return (total_len);
}

int	ft_check_hex(t_list *spec, unsigned int n, int upper)
{
	int		zeros;
	int		padding;
	int		total_len;
	char	fill_char;

	total_len = 0;
	zeros = ft_calc_zeros_hex(n, spec);
	padding = ft_calc_padding_hex(n, spec, zeros);
	fill_char = ft_get_fill_char(spec);
	if (!spec->minus && fill_char == ' ')
		total_len += ft_padding(fill_char, padding);
	total_len += ft_put_hex_prefix(spec, n, upper);
	if (!spec->minus && fill_char == '0' && spec->dot < 0)
		total_len += ft_padding('0', padding);
	total_len += ft_putzeros(zeros);
	if (!(n == 0 && spec->dot == 0))
		total_len += ft_putnbr_hex(n, upper);
	if (spec->minus)
		total_len += ft_padding(' ', padding);
	return (total_len);
}

int	ft_check(t_list *spec, va_list args)
{
	if (spec->specifier == 'd' || spec->specifier == 'i')
		return (ft_check_int(spec, va_arg(args, int)));
	if (spec->specifier == 'c')
		return (ft_check_char(spec, va_arg(args, int)));
	if (spec->specifier == 's')
		return (ft_check_string(spec, va_arg(args, char *)));
	if (spec->specifier == 'p')
		return (ft_check_ptr(spec, va_arg(args, void *)));
	if (spec->specifier == 'u')
		return (ft_check_unsigned(spec, va_arg(args, unsigned int)));
	if (spec->specifier == 'x')
		return (ft_check_hex(spec, va_arg(args, unsigned int), 0));
	if (spec->specifier == 'X')
		return (ft_check_hex(spec, va_arg(args, unsigned int), 1));
	if (spec->specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_list	spec;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_parse_format(format, &spec);
			count += ft_check(&spec, args);
		}
		else
		{
			count += ft_putchar(*format++);
		}
	}
	va_end(args);
	return (count);
}
