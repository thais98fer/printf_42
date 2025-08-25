/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:44:29 by thais.fer         #+#    #+#             */
/*   Updated: 2025/08/22 13:59:04 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	ft_init_specifier(void)
{
	t_list	spec;

	spec.minus = 0;
	spec.plus = 0;
	spec.zero = 0;
	spec.dot = -1;
	spec.hash = 0;
	spec.space = 0;
	spec.width = 0;
	spec.specifier = 0;
	return (spec);
}
