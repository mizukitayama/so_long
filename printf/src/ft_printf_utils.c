/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:24:01 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/23 12:12:53 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_nbrlen(int n, int accumulator);

int	ft_putchar(int c)
{
	return ((int)write(1, (const void *)&c, 1));
}

int	ft_putstr(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return ((int)ft_strlen_printf(s));
}

int	ft_putnbr(int i)
{
	ft_putnbr_fd(i, 1);
	return (count_nbrlen(i, 0));
}

static int	count_nbrlen(int n, int accumulator)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		accumulator++;
	}
	if (n < 10)
		return (accumulator + 1);
	else
		return (count_nbrlen(n / 10, accumulator + 1));
}

int	ft_cnt_hlen(unsigned long long pnt, int acc)
{
	if (pnt < 16)
		return (acc + 1);
	else
		return (ft_cnt_hlen(pnt / 16, acc + 1));
}
