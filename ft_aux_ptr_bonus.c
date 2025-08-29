/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_ptr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:04:35 by thais.fer         #+#    #+#             */
/*   Updated: 2025/08/28 20:31:27 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_check_ptr(t_list *spec, void *ptr)
{
	int	count;
	int	zeros;
	int	padding;

	count = 0;
	if (!ptr)
		return (ft_check_string(spec, "(nil)"));
	zeros = ft_calc_zeros_ptr((unsigned long)ptr, spec);
	padding = ft_calc_padding_ptr((unsigned long)ptr, spec, zeros);
	if (!spec->minus)
		count += ft_padding(' ', padding);
	count += ft_putstr("0x");
	count += ft_putzeros(zeros);
	count += ft_putnbr_base((unsigned long)ptr, 16, 0);
	if (spec->minus)
		count += ft_padding(' ', padding);
	return (count);
}

int	ft_calc_zeros_ptr(unsigned long ptr, t_list *spec)
{
	int	len;

	len = ft_numlen_base(ptr, 16);
	if (spec->dot > len)
		return (spec->dot - len);
	return (0);
}

int	ft_calc_padding_ptr(unsigned long ptr, t_list *spec, int zeros)
{
	int	len;

	len = ft_numlen_base(ptr, 16);
	if (spec->width > len)
		return (spec->width - (len + zeros + 2));
	return (0);
}

int	ft_put_hex_prefix(t_list *spec, int n, int upper)
{
	int	count;

	count = 0;
	if (spec->hash && n != 0)
	{
		count += ft_putchar('0');
		if (upper == 1)
			count += ft_putchar('X');
		else
			count += ft_putchar('x');
	}
	return (count);
}

int	ft_get_strlen_null(t_list *spec, char **str)
{
	int	len;

	if (*str == NULL)
	{
		*str = "(null)";
		if (spec->dot >= 0 && spec->dot < 6)
			len = 0;
		else
			len = 6;
	}
	else
		len = ft_strlen(*str);
	return (len);
}
