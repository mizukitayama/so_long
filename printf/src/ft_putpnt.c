/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:25:29 by mtayama           #+#    #+#             */
/*   Updated: 2023/03/14 17:25:36 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_hex(unsigned long int pnt);

int	ft_putpnt(unsigned long int pnt)
{
	int	size;

	size = 0;
	size += ft_putstr("0x");
	if (pnt == 0)
		size += ft_putchar('0');
	else
	{
		ft_write_hex(pnt);
		size += ft_cnt_hlen(pnt, 0);
	}
	return (size);
}

static void	ft_write_hex(unsigned long int pnt)
{
	if (pnt < 16)
		write(1, &"0123456789abcdef"[pnt], 1);
	else
	{
		ft_write_hex(pnt / 16);
		ft_write_hex(pnt % 16);
	}
}
