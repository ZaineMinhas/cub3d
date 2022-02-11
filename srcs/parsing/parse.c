/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:40:53 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/11 18:55:16 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	skip_info(char *line, int *i, int fd, int info_type)
{
	if (!info_type)
	{
		while (ft_is_white_space(line[*i]))
			i++;
		if (ft_isdigit(line[*i]))
		{
			close(fd);
			free(line);
			return (1);
		}
		return (0);
	}
	return (0);
}

int	get_line(char *line, t_cub *cub)
{
	static int	j;

	if (line[0])
	{
		cub->map->info[j] = ft_strdup(line);
		if (!cub->map->info[j] && j != 8)
		{
			free_double_char(cub->map->info);
			return (1);
		}
		j++;
	}
	return (0);
}

int	get_map(int fd, char *line, char **argv, t_cub *cub)
{
	int		i;

	(void)cub;
	(void)i;
	(void)argv;
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	return (1);
}

int	get_info(char **argv, t_cub *cub)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		i = 0;
		if (skip_info(line, &i, fd, 0))
			break;
		if (get_line(line, cub))
			return (0);
		free(line);
	}
	/*if (!get_map(fd, line, argv, cub))		----get map-----
		return (0);*/
	close(fd);
	return (1);
}

int	parse(char **argv, t_cub *cub)
{
	if (!get_info(argv, cub))
		return (free_all(cub));
	return (0);
}
