/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:13:27 by mtayama           #+#    #+#             */
/*   Updated: 2024/01/12 18:04:33 by mtayama          ###   ########.fr       */
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

static char	*ft_strdup(const char *s)
{
	char	*t;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (t == 0)
		return (0);
	while (s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
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
		return ((void *)ft_strdup(""));
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