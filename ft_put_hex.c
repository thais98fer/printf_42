/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:18:05 by thfernan          #+#    #+#             */
/*   Updated: 2025/08/13 16:43:55 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

int	ft_put_hex(unsigned int nb, char upper)
{
	int		count;
	char	c;

	count = 0;
	c = 0;
	if (nb >= 16)
		count += ft_put_hex((nb / 16), upper);
	if ((nb % 16) < 10)
		c = (nb % 16) + '0';
	else
		c = ((nb % 16) - 10) + 'a';
	if (upper)
		c = ft_toupper(c);
	count += ft_putchar_fd(c, 1);
	return (count);
}
