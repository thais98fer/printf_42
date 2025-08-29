/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:57:01 by thais.fer         #+#    #+#             */
/*   Updated: 2025/08/28 20:31:48 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

const char	*ft_parse_flags(const char *format, t_list *spec)
{
	while (*format == '-' || *format == '0' || *format == '#'
		|| *format == ' ' || *format == '+')
	{
		if (*format == '-')
			spec->minus = 1;
		if (*format == '+')
			spec->plus = 1;
		if (*format == '0')
			spec->zero = 1;
		if (*format == '#')
			spec->hash = 1;
		if (*format == ' ')
			spec->space = 1;
		format++;
	}
	return (format);
}

const char	*ft_parse_width(const char *format, t_list *spec)
{
	if (*format >= '0' && *format <= '9')
	{
		while (*format >= '0' && *format <= '9')
		{
			spec->width = spec->width * 10 + (*format - '0');
			format++;
		}
	}
	return (format);
}

const char	*ft_parse_precision(const char *format, t_list *spec)
{
	if (*format == '.')
	{
		spec->dot = 0;
		format++;
		while (*format >= '0' && *format <= '9')
		{
			spec->dot = spec->dot * 10 + (*format - '0');
			format++;
		}
	}
	else
		spec->dot = -1;
	return (format);
}
