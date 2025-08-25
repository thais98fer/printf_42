/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counts_put_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:18:51 by thais.fer         #+#    #+#             */
/*   Updated: 2025/08/25 13:01:36 by thais.fer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_signed(long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

int	ft_numlen_base(unsigned long n, int base)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		length++;
	}
	return (length);
}

int	ft_numlen_hex(unsigned long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		length++;
	}
	return (length);
}

int	ft_putzeros(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += ft_putchar('0');
		n--;
	}
	return (count);
}

int	ft_putsign(int n, t_list *spec)
{
	if (n < 0)
		return (ft_putchar('-'));
	if (spec->plus)
		return (ft_putchar('+'));
	if (spec->space)
		return (ft_putchar(' '));
	return (0);
}
