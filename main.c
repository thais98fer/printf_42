/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:50:46 by thfernan          #+#    #+#             */
/*   Updated: 2025/08/25 14:41:24 by thais.fer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <limits.h>
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

	printf("\n==== TESTES ft_printf vs printf ====\n\n");

    // 1. FLAGS BÁSICAS
    printf("1. FLAGS BÁSICAS\n");
    size_o = printf("O: |%+d| |% d| |%05d| |%-5d|\n", d, i, i, i);
    size_m = ft_printf("M: |%+d| |% d| |%05d| |%-5d|\n", d, i, i, i);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 2. Precisão
    printf("2. PRECISÃO\n");
    size_o = printf("O: |%.5d| |%.8i| |%.3s|\n", i, d, str);
    size_m = ft_printf("M: |%.5d| |%.8i| |%.3s|\n", i, d, str);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 3. Combinações
    printf("3. COMBINAÇÕES\n");
    size_o = printf("O: |%+05d| |% 05d| |%-5d| |%08.3d| |%#08x|\n", i, i, i, i, hex);
    size_m = ft_printf("M: |%+05d| |% 05d| |%-5d| |%08.3d| |%#08x|\n", i, i, i, i, hex);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 4. Hexadecimal
    printf("4. HEXADECIMAL\n");
    size_o = printf("O: |%#x| |%#X|\n", hex, hex);
    size_m = ft_printf("M: |%#x| |%#X|\n", hex, hex);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 5. Unsigned
    printf("5. UNSIGNED\n");
    size_o = printf("O: |%u|\n", u);
    size_m = ft_printf("M: |%u|\n", u);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 6. Ponteiros
    printf("6. PONTEIROS\n");
    size_o = printf("O: |%p| |%20p|\n", pointer, pointer);
    size_m = ft_printf("M: |%p| |%20p|\n", pointer, pointer);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 7. Caracteres e strings
    printf("7. CHARS e STRINGS\n");
    size_o = printf("O: |%c| |%5c| |%-5c| |%.3s|\n", c, c, c, str);
    size_m = ft_printf("M: |%c| |%5c| |%-5c| |%.3s|\n", c, c, c, str);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 8. Porcento
    printf("8. PORCENTO\n");
    size_o = printf("O: |%%| |%5%| |%-5%|\n");
    size_m = ft_printf("M: |%%| |%5%| |%-5%|\n");
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	 // 9. Valores extremos
    printf("9. VALORES EXTREMOS\n");
    size_o = printf("O: |%d| |%d|\n", INT_MIN, INT_MAX);
    size_m = ft_printf("M: |%d| |%d|\n", INT_MIN, INT_MAX);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	printf("10. MAIS TESTES\n");
    size_o = printf("O: |%.5d| |%.8i| |%.3s|\n", i, d, str2);
    size_m = ft_printf("M: |%.5d| |%.8i| |%.3s|\n", i, d, str2);
	printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	printf("s = NULL\n");
	size_o = printf("O: |%.09s| |%3.6s| |%20.6s| |%-3.8s| |%-10.8s|\n", str2, str2, str2, str2, str2);
    size_m = ft_printf("M: |%.09s| |%3.6s| |%20.6s| |%-3.8s| |%-10.8s|\n", str2, str2, str2, str2, str2);
	printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	printf("i = 0\n");
	size_o = printf("O: |%5.0i| |%5.i| |%-5.0i|\n", in, in, in);
    size_m = ft_printf("M: |%5.0i| |%5.i| |%-5.0i|\n", in, in, in);
	printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	printf("u = 0\n");
	size_o = printf("O: |%5.0u| |%5.u| |%-5.0u|\n", un, un, un);
    size_m = ft_printf("M: |%5.0u| |%5.u| |%-5.0u|\n", un, un, un);
	printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	printf("x = 0\n");
	size_o = printf("O: |%5.0x| |%5.x| |%-5.0x|\n", hexz, hexz, hexz);
    size_m = ft_printf("M: |%5.0x| |%5.x| |%-5.0x|\n", hexz, hexz, hexz);
	printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	printf("X = 0\n");
	size_o = printf("O: |%5.0X| |%5.X| |%-5.0X|\n", hexz, hexz, hexz);
    size_m = ft_printf("M: |%5.0X| |%5.X| |%-5.0X|\n", hexz, hexz, hexz);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	size_o = printf("O: |%05u| |%03u| |%020u| |%020u|\n", tes, un, 1024, -1024);
    size_m = ft_printf("M: |%05u| |%03u| |%020u| |%020u|\n", tes, un, 1024, -1024);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);
	return (0);
}
