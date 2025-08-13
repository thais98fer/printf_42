/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:50:46 by thfernan          #+#    #+#             */
/*   Updated: 2025/08/13 17:42:05 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	"ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_fd("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s || fd < 0)
		return (count += (ft_putstr_fd("(null)", 1)));
	while (*s)
	{
		count += ft_putchar_fd(*s, fd);
		s++;
	}
	return (count);
}

int	ft_check(char c, va_list args)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (c == 'p')
		return (ft_put_adress((unsigned long int)va_arg(args, void *)));
	if (c == 'u')
		return (ft_put_dec(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_put_perc());
	if (c == 'x')
		return (ft_put_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), 1));
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
			count += ft_putchar_fd(*format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int				c = 'l';
	char			*str = "Teste";
	void			*pointer = str;
	int				d = -42;
	int				i = 123;
	int				hex = 255;
	unsigned int	u = -42;
	int				size_o; //Retorno printf original
	int				size_m; // Retorno minha printf

	printf("=== Original printf ===\n");
    size_o = printf("char: %c, string: %s, ponteiro: %p, decimal: %d, inteiro: %i, unsigned: %u, hex: %x, HEX: %X, porcento: %%\n", c, str, pointer, d, i, u, hex, hex);
    printf("Retorno printf: %d\n\n", size_o);

    printf("=== Minha ft_printf ===\n");
    size_m = ft_printf("char: %c, string: %s, ponteiro: %p, decimal: %d, inteiro: %i, unsigned: %u, hex: %x, HEX: %X, porcento: %%\n", c, str, pointer, d, i, u, hex, hex);
    printf("Retorno ft_printf: %d\n", size_m);
	return (0);
}*/