/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:34:00 by zminhas           #+#    #+#             */
/*   Updated: 2021/02/19 15:37:39 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_line(int color, t_cub *var, float rot)
{
	float	dx;
	float	dy;
	int		i;

	i = -1;
	dx = 0;
	dy = 0;
	while (++i < 2225 && !ft_is_wall(var->p_x + dx, var->p_y - dy))
	{
		dx += cos(((float)var->rot + rot) * (M_PI / 180));
		dy += sin(((float)var->rot + rot) * (M_PI / 180));
		mlx_pixel_put(var->mlx_ptr, var->win_ptr,
		dx + var->p_x, var->p_y - dy, color);
	}
}

void	ft_square(t_cub *var, int color)
{
	float x;
	float y;

	y = -1;
	while (++y < 6)
	{
		x = -1;
		while (++x < 6)
			mlx_pixel_put(var->mlx_ptr, var->win_ptr, var->p_x + y - 3,
			var->p_y + x - 3, color);
	}
	if (color)
		color = g_white;
	y = -45;
	while (y < 46)
	{
		y += 1;
		ft_line(color, var, y);
	}
}
