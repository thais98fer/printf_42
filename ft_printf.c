/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:50:46 by thfernan          #+#    #+#             */
/*   Updated: 2025/08/25 14:45:49 by thais.fer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(unsigned long int nbr, int base, int is_signed, int upper)
{
	int		count;
	char	*digits;

	count = 0;
	if (upper == 1)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (is_signed && (long)nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -(long)nbr;
	}
	if (nbr >= (unsigned long)base)
		count += ft_putnbr(nbr / base, base, 0, upper);
	else if (nbr == 0 && base == 16)
		return (ft_putchar('0'));
	count += ft_putchar(digits[nbr % base]);
	return (count);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}

int	ft_check(char c, va_list args)
{
	void	*ptr;

	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), 10, 1, 0));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x") + ft_putnbr((unsigned long int)ptr, 16, 0, 0));
	}
	if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 10, 0, 0));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'x')
		return (ft_putnbr(va_arg(args, unsigned int), 16, 0, 0));
	if (c == 'X')
		return (ft_putnbr(va_arg(args, unsigned int), 16, 0, 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_check(*format, args);
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
int	main(void)
{
	int				c = 'l';
	char			*str = "Teste";
	char			*str2 = NULL;
	void			*pointer = str;
	int				d = -42;
	int				i = 123;
	int				in = 0;
	int				hex = 255;
	int				hexz = 0;
	unsigned int	u = -42;
	unsigned int	un = 0;
	unsigned int	tes = 43;
	int				size_o; // Retorno printf original
	int				size_m; // Retorno minha printf

	printf("=== Original printf ===\n");
    size_o = printf("char: %c, string: %s, ponteiro: %p, decimal: %d, inteiro: %i, unsigned: %u, hex: %x, HEX: %X, porcento: %%\n", c, str, pointer, d, i, u, hex, hex);
    printf("Retorno printf: %d\n\n", size_o);

    printf("=== Minha ft_printf ===\n");
    size_m = ft_printf("char: %c, string: %s, ponteiro: %p, decimal: %d, inteiro: %i, unsigned: %u, hex: %x, HEX: %X, porcento: %%\n", c, str, pointer, d, i, u, hex, hex);
    printf("Retorno ft_printf: %d\n\n", size_m);

    printf("VALORES EXTREMOS\n");
    size_o = printf("O: |%d| |%d|\n", INT_MIN, INT_MAX);
    size_m = ft_printf("M: |%d| |%d|\n", INT_MIN, INT_MAX);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);
	return (0);
}