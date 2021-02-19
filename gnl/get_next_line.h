/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:10:16 by zminhas           #+#    #+#             */
/*   Updated: 2021/02/19 15:43:19 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 69

char	*ft_check_error(int fd, char **line);
int		ft_backslash_checker(char *str);
char	*ft_strjoin_remix(char const *s1, char const *s2);
char	*ft_get_line(char *str);
int		get_next_line(int fd, char **line);

size_t	ft_strlen_protect(const char *s);
void	*ft_calloc_remix(int count, int size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup_remix(char *s1);
char	*ft_strchr_dup_remix(const char *s, int c);

#endif
