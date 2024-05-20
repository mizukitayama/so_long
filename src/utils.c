/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:13:27 by mtayama           #+#    #+#             */
/*   Updated: 2024/01/12 23:21:12 by mtayama          ###   ########.fr       */
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

static void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = (unsigned char *)str;
	while (i < n)
	{
		*s_cpy = (unsigned char)c;
		s_cpy++;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*p;

	if ((number * size) == 0)
		return (NULL);
	if (size != 0 && number > (size_t)SIZE_MAX / size)
	{
		return (NULL);
	}
	p = malloc(number * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, '\0', number * size);
	return (p);
}
