/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:23:44 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/23 12:12:10 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int i);
int	ft_putpnt(unsigned long int pnt);
int	ft_putuint(unsigned int ui);
int	ft_puthex(unsigned int ui, char c);
int	ft_cnt_hlen(unsigned long long pnt, int acc);

#endif
