/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:28:10 by thais.fer         #+#    #+#             */
/*   Updated: 2025/08/28 20:32:04 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr_base(unsigned long nbr, int base, int upper)
{
	int		count;
	char	*digits;

	count = 0;
	if (upper == 1)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (nbr >= (unsigned long)base)
		count += ft_putnbr_base(nbr / base, base, upper);
	count += ft_putchar(digits[nbr % base]);
	return (count);
}

int	ft_putnbr_signed(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
		count += ft_putnbr_base(-(long)nbr, 10, 0);
	else
		count += ft_putnbr_base(nbr, 10, 0);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	return (ft_putnbr_base(nbr, 10, 0));
}

int	ft_putnbr_hex(unsigned int nbr, int upper)
{
	return (ft_putnbr_base(nbr, 16, upper));
}
