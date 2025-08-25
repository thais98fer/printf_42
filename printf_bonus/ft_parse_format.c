/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:56:09 by thais.fer         #+#    #+#             */
/*   Updated: 2025/08/19 10:15:31 by thais.fer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
