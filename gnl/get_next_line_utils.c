/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:16:55 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/26 17:10:56 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_protect(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(int count, int size)
{
	char		*dest;
	int			i;

	if (!(dest = (char *)malloc(sizeof(void) * (size * count))))
		return (NULL);
	i = -1;
	while (++i < size * count)
		dest[i] = 0;
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src2;
	char		*dest2;

	if (!src && !dest)
		return (dest);
	dest2 = (char *)dest;
	src2 = (const char *)src;
	while (n-- > 0)
		dest2[n] = src2[n];
	return ((void *)dest2);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;

	if (!s1)
		return (NULL);
	if (!(dest = (char *)ft_calloc(sizeof(char), (ft_strlen_protect(s1) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	return (dest);
}

char	*ft_strchr_dup_remix(const char *s, int c)
{
	char	*dest;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
		{
			dest = ft_strdup((char *)(s + i + 1));
			free((void *)s);
			return (dest);
		}
	free((void *)s);
	return (NULL);
}
