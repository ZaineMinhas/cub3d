/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:30:56 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/28 18:12:29 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *s2;
	size_t				i;

	s2 = (unsigned const char *)s;
	i = -1;
	while (++i < n)
		if (s2[i] == (unsigned const char)c)
			return ((void *)(s + i));
	return (NULL);
}
