/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_get_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:37:51 by zminhas           #+#    #+#             */
/*   Updated: 2021/02/17 17:46:14 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_get_info(char *line, int i)
{
	int j;

	while (line[i] == ' ')
		i++;
	j = ft_strlen(line) - 1;
	while (line[j] == ' ')
		j--;
	return (ft_substr(line, (unsigned int)i, (size_t)j));
}

void	ft_get_resolution(t_map *info, char *line)
{
	char **str;

	str = ft_split(line, ' ');
	info->r[0] = ft_atoi(str[1]);
	info->r[1] = ft_atoi(str[2]);
}

void	ft_get_color_f(t_map *info, char *line)
{
	char **str;

	str = ft_split(line + 1, ',');
	info->f[0] = ft_atoi(str[0]);
	info->f[1] = ft_atoi(str[1]);
	info->f[2] = ft_atoi(str[2]);
}

void	ft_get_color_c(t_map *info, char *line)
{
	char **str;

	str = ft_split(line + 1, ',');
	info->c[0] = ft_atoi(str[0]);
	info->c[1] = ft_atoi(str[1]);
	info->c[2] = ft_atoi(str[2]);
}

void	ft_info(t_map *info/*, char **argv*/)
{
	char	*line;
	int		fd;

	if (!(fd = open("fichier.cub", O_RDONLY)))
		return ;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R')
			ft_get_resolution(info, line);
		else if (line[0] == 'N')
			info->no = ft_get_info(line, 2);
		else if (line[0] == 'W')
			info->we = ft_get_info(line, 2);
		else if (line[0] == 'E')
			info->ea = ft_get_info(line, 2);
		else if (line[0] == 'F')
			ft_get_color_f(info, line);
		else if (line[0] == 'C')
			ft_get_color_c(info, line);
		else if (line[0] == 'S' && line[1] == 'O')
			info->so = ft_get_info(line, 2);
		else if (line[0] == 'S')
			info->s = ft_get_info(line, 1);
	}
	close(fd);
}
