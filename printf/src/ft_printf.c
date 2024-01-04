/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:20:24 by mtayama           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:39 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_cvs(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putpnt((unsigned long int)va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return ((int)write(1, &"%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			size += handle_cvs(args, str[i + 1]);
			i += 2;
		}
		else
		{
			size += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (size);
}

// #include <stdio.h>
// int main()
// {
// 	//char
// 	puts("(c)");
// 	int sizec = ft_printf("%c\n", 'z');
// 	int sizec2 = printf("%c\n", 'z');
// 	printf("%d, %d\n\n", sizec, sizec2);

// 	//string
// 	puts("(s)");
// 	int sizes = ft_printf("%s\n", NULL);
// 	int sizes2 = printf("%s\n", NULL);
// 	printf("%d, %d\n\n", sizes, sizes2);

// 	//int
// 	puts("(d)");
// 	int sized = ft_printf("%d\n", 2147483647);
// 	int sized2 = printf("%d\n", 2147483647);
// 	printf("%d, %d\n\n", sized, sized2);
// 	// int sized_2 = ft_printf("%d\n", -2147483648);
// 	// int sized_22 = printf("%d\n", -2147483648);
// 	// printf("%d, %d\n\n", sized_2, sized_22);

// 	puts("(i)");
// 	int sizei = ft_printf("%i\n", 2147483647);
// 	int sizei2 = printf("%i\n", 2147483647);
// 	printf("%d, %d\n\n", sizei, sizei2);

// 	//unsigned int
// 	puts("(u)");
// 	int sizeu = ft_printf("%u\n", -121234);
// 	int sizeu2 = printf("%u\n", -121234);
// 	printf("%d, %d\n\n", sizeu, sizeu2);

// 	//address(p)
// 	puts("(p)");
// 	int sizep = ft_printf("%p\n", "1234");
// 	int sizep2 = printf("%p\n", "1234");
// 	printf("%d, %d\n\n", sizep, sizep2);

// 	//hexadecimal
// 	puts("(x)");
// 	int sizex = ft_printf("%x\n", 12345678);
// 	int sizex2 = printf("%x\n", 12345678);
// 	printf("%d, %d\n\n", sizex, sizex2);

// 	puts("(X)");
// 	int sizeX = ft_printf("%X\n", 12345678);
// 	int sizeX2 = printf("%X\n", 12345678);
// 	printf("%d, %d\n\n", sizeX, sizeX2);

// 	//conversion%
// 	puts("(%)");
// 	int sizepp = ft_printf("%%\n");
// 	int sizepp2 = printf("%%\n");
// 	printf("%d, %d\n\n", sizepp, sizepp2);

// // 	puts("====");
// // 	int test = ft_printf("%cTesting%s%pmy%d\n%i\n%uprintf\n%x\n%X%%",
// // 'o', "\nfaim\naaa\n", "(", 1234443, 11111, 543343454, 1234, 1234);
// // 	puts("====");
// // 	int test2 = printf("%cTesting%s%pmy%d\n%i\n%uprintf\n%x\n%X%%",
// // 'o', "\nfaim\naaa\n", "(", 1234443, 11111, 543343454, 1234, 1234);
// // 	puts("====");
// // 	printf("%d, %d", test, test2);
// }
