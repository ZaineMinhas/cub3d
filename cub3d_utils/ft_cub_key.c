/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:39:10 by zminhas           #+#    #+#             */
/*   Updated: 2021/02/17 17:47:18 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_go(int key, t_cub *var)
{
	if (key == 53 /*esc*/)
		exit(1);
	else if (key == 123 /*left*/)
		ft_look_left(var);
	else if (key == 124 /*right*/)
		ft_look_right(var);
	if (key == 13 /*w*/)
		ft_go_w(var);
	else if (key == 0 /*a*/)
		ft_go_a(var);
	else if (key == 1 /*s*/)
		ft_go_s(var);
	else if (key == 2 /*d*/)
		ft_go_d(var);
	return (0);
}
