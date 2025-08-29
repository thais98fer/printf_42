/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_zeros_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:52:30 by thais.fer         #+#    #+#             */
/*   Updated: 2025/08/28 20:31:42 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_padding(char c, int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += ft_putchar(c);
		n--;
	}
	return (count);
}

char	ft_get_pad_char(t_list *spec)
{
	if (spec->zero && spec->dot < 0 && !spec->minus)
		return ('0');
	return (' ');
}

char	ft_get_fill_char(t_list *spec)
{
	if (spec->dot >= 0)
		return (' ');
	return (ft_get_pad_char(spec));
}

int	ft_calc_zeros(int n, t_list *spec)
{
	int	num_len;

	num_len = ft_numlen_signed(ft_nbr_abs(n));
	if (spec->dot > num_len)
		return (spec->dot - num_len);
	return (0);
}

int	ft_calc_padding(int n, t_list *spec, int zeros)
{
	int	pad;
	int	num_len;

	num_len = ft_numlen_signed(ft_nbr_abs(n));
	if (n == 0 && spec->dot == 0)
		num_len = 0;
	if (n < 0 || spec->plus || spec->space)
		num_len += 1;
	pad = spec->width - (num_len + zeros);
	if (pad < 0)
		pad = 0;
	return (pad);
}
