/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:13:57 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/26 17:27:31 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_error(int fd, char **line)
{
	char	*buff;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || !line)
		return (NULL);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	return (buff);
}

int		ft_backslash_checker(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin_remix(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;

	size = ft_strlen_protect(s1) + ft_strlen_protect(s2) + 1;
	if (!(dest = (char *)ft_calloc(sizeof(char), size)))
	{
		if (s1)
			free((void *)s1);
		return (NULL);
	}
	ft_memcpy(dest, s1, ft_strlen_protect(s1));
	ft_memcpy(dest + ft_strlen_protect(s1), s2, ft_strlen_protect(s2));
	free((void *)s1);
	return (dest);
}

char	*ft_get_line(char *str)
{
	size_t	size;
	char	*dest;

	if (!str)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	if (!(dest = (char *)ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '\n')
	{
		dest[size] = str[size];
		size++;
	}
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	static char *str_save;
	char		*buff;
	int			i;

	if (!(buff = ft_check_error(fd, line)))
		return (-1);
	i = 1;
	while (!ft_backslash_checker(str_save) && i)
	{
		if ((i = (int)read(fd, buff, BUFFER_SIZE)) < 0)
		{
			free(buff);
			return (-1);
		}
		buff[i] = 0;
		if (!(str_save = ft_strjoin_remix(str_save, buff)))
			return (-1);
	}
	free(buff);
	if (!(*line = ft_get_line(str_save)) ||\
	(!(str_save = ft_strchr_dup_remix(str_save, '\n')) && i != 0))
		return (-1);
	if (i)
		return (1);
	return (0);
}
