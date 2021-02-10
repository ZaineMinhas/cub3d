/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:53:01 by zminhas           #+#    #+#             */
/*   Updated: 2021/02/10 19:41:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>

int g_rose = 32123123;
int g_orange = 100100100;
int g_red = 150150150;

typedef struct	s_cublist
{
	float	p_x;
	float	p_y;
	int rot;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_cublist;

#endif
