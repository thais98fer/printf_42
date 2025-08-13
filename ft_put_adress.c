/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:36:54 by thfernan          #+#    #+#             */
/*   Updated: 2025/08/13 16:43:45 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_put_adress(unsigned long int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (ft_putstr_fd("(nil)", 1));
	if (nb / 16 == 0)
		count += ft_putstr_fd("0x", 1);
	if (nb >= 16)
		count += ft_put_adress(nb / 16);
	if ((nb % 16) < 10)
		count += ft_putchar_fd((nb % 16) + '0', 1);
	else
		count += ft_putchar_fd(((nb % 16) - 10) + 'a', 1);
	return (count);
}
