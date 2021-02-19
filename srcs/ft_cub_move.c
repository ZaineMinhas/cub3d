/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:34:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/02/17 17:49:01 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_go_w(t_cub *var)
{
	float dx;
	float dy;

	ft_square(var, 0);
	dx = cos((M_PI / 180) * var->rot) * 10;
	dy = sin((M_PI / 180) * var->rot) * 10;
	if (!ft_is_wall(var->p_x + dx, var->p_y - dy))
	{
		var->p_x += dx;
		var->p_y -= dy;
	}
	ft_square(var, g_rose);
}

void	ft_go_a(t_cub *var)
{
	float dx;
	float dy;

	ft_square(var, 0);
	dx = cos((M_PI / 180) * var->rot) * 10;
	dy = sin((M_PI / 180) * var->rot) * 10;
	if (!ft_is_wall(var->p_x - dy, var->p_y - dx))
	{
		var->p_x -= dy;
		var->p_y -= dx;
	}
	ft_square(var, g_rose);
}

void	ft_go_s(t_cub *var)
{
	float dx;
	float dy;

	ft_square(var, 0);
	dx = cos((M_PI / 180) * var->rot) * 10;
	dy = sin((M_PI / 180) * var->rot) * 10;
	if (!ft_is_wall(var->p_x - dx, var->p_y + dy))
	{
		var->p_x -= dx;
		var->p_y += dy;
	}
	ft_square(var, g_rose);
}

void	ft_go_d(t_cub *var)
{
	float dx;
	float dy;

	ft_square(var, 0);
	dx = cos((M_PI / 180) * var->rot) * 10;
	dy = sin((M_PI / 180) * var->rot) * 10;
	if (!ft_is_wall(var->p_x + dy, var->p_y + dy))
	{
		var->p_x += dy;
		var->p_y += dx;
	}
	ft_square(var, g_rose);
}
