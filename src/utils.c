/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:13:27 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/26 17:42:31 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_c(char *str, char ch)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == ch)
			count++;
		str++;
	}
	return (count);
}

size_t	strlen_ignore_new_line(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		len--;
	return (len);
}
