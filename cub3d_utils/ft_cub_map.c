/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:31:22 by zminhas           #+#    #+#             */
/*   Updated: 2021/02/17 17:48:38 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_reset(void *mlx_ptr, void *win_ptr)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x < 1921)
	{
		y = -1;
		while (++y < 1081)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 255255255);
	}
}

void	ft_wall(t_cub var, int wall, int x, int y)
{
	int i;
	int j;

	if (!wall)
		return ;
	i = -1;
	while (++i < 98)
	{
		j = -1;
		while (++j < 98)
			mlx_pixel_put(var.mlx_ptr, var.win_ptr,
			x * 100 + i + 1, y * 100 + j + 1, g_orange);
	}
}

void	ft_map(t_cub var)
{
	int i;
	int j;
	int map_x;
	int map_y;

	map_x = 20;
	map_y = 10;
	i = -1;
	while (++i < map_x)
	{
		j = -1;
		while (++j < map_y)
			ft_wall(var, g_map[j][i], i, j);
	}
}

int		ft_is_wall(int x, int y)
{
	if (g_map[y / 100][x / 100])
		return (1);
	return (0);
}
