/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:24:51 by mtayama           #+#    #+#             */
/*   Updated: 2023/03/14 17:26:32 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_hex(unsigned int ui, char c);

int	ft_puthex(unsigned int ui, char c)
{
	ft_write_hex(ui, c);
	return (ft_cnt_hlen(ui, 0));
}

static void	ft_write_hex(unsigned int ui, char c)
{
	if (ui < 16)
	{
		if (c == 'x')
			write(1, &"0123456789abcdef"[ui], 1);
		else if (c == 'X')
			write(1, &"0123456789ABCDEF"[ui], 1);
	}
	else
	{
		ft_write_hex(ui / 16, c);
		ft_write_hex(ui % 16, c);
	}
}
