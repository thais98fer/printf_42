/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:42:55 by thfernan          #+#    #+#             */
/*   Updated: 2025/08/13 16:43:51 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_put_dec(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_dec(n / 10);
	count += ft_putchar_fd((n % 10) + '0', 1);
	return (count);
}
