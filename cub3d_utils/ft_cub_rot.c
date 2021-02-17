/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:36:39 by zminhas           #+#    #+#             */
/*   Updated: 2021/02/17 17:49:24 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_look_right(t_cub *var)
{
	ft_square(var, 0);
	var->rot -= 5;
	var->rot %= 360;
	ft_square(var, g_rose);
}

void	ft_look_left(t_cub *var)
{
	ft_square(var, 0);
	var->rot += 5;
	var->rot %= 360;
	ft_square(var, g_rose);
}
