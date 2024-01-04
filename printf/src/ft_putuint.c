/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:26:04 by mtayama           #+#    #+#             */
/*   Updated: 2023/03/14 17:26:37 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_ui(unsigned int ui);
static int	ft_cnt_uint(unsigned int ui, int acc);

int	ft_putuint(unsigned int ui)
{
	ft_write_ui(ui);
	return (ft_cnt_uint(ui, 0));
}

static void	ft_write_ui(unsigned int ui)
{
	if (ui <= 9)
		write(1, &"0123456789"[ui], 1);
	else
	{
		ft_write_ui(ui / 10);
		ft_write_ui(ui % 10);
	}
}

static int	ft_cnt_uint(unsigned int ui, int acc)
{
	if (ui < 10)
		return (acc + 1);
	else
		return (ft_cnt_uint(ui / 10, acc + 1));
}
