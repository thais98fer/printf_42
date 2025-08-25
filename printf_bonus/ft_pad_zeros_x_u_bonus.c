/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_zeros_x_u_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:34:19 by thfernan          #+#    #+#             */
/*   Updated: 2025/08/25 13:01:15 by thais.fer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_abs(int n)
{
	int	abs_n;

	abs_n = 0;
	if (n < 0)
		abs_n = n * -1;
	else
		abs_n = n;
	return (abs_n);
}

int	ft_calc_padding_unsigned(unsigned long n, t_list *spec, int zeros)
{
	int	pad;
	int	num_len;

	num_len = ft_numlen_base(n, 10);
	if (n == 0 && spec->dot == 0)
		num_len = 0;
	num_len += zeros;
	pad = spec->width - num_len;
	if (pad < 0)
		pad = 0;
	return (pad);
}

int	ft_calc_zeros_unsigned(unsigned long n, t_list *spec)
{
	int	len;

	if (n == 0 && spec->dot == 0)
		return (0);
	len = ft_numlen_base(n, 10);
	if (spec->dot > len)
		return (spec->dot - len);
	return (0);
}

int	ft_calc_zeros_hex(unsigned int n, t_list *spec)
{
	int	len;

	len = ft_numlen_base(n, 16);
	if (spec->dot > len)
		return (spec->dot - len);
	return (0);
}

int	ft_calc_padding_hex(unsigned int n, t_list *spec, int zeros)
{
	int	pad;
	int	num_len;

	num_len = ft_numlen_base(n, 16);
	if (n == 0 && spec->dot == 0)
		num_len = 0;
	num_len += zeros;
	if (spec->hash && n != 0)
		num_len += 2;
	pad = spec->width - num_len;
	if (pad < 0)
		pad = 0;
	return (pad);
}
