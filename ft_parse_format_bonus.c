/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:56:09 by thais.fer         #+#    #+#             */
/*   Updated: 2025/08/28 20:31:50 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

const char	*ft_parse_format(const char *format, t_list *spec)
{
	*spec = ft_init_specifier();
	format++;
	format = ft_parse_flags(format, spec);
	format = ft_parse_width(format, spec);
	format = ft_parse_precision(format, spec);
	format = ft_parse_specifier(format, spec);
	return (format);
}
