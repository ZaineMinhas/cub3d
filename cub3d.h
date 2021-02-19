/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:53:01 by zminhas           #+#    #+#             */
/*   Updated: 2021/02/19 17:16:39 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

int g_rose;
int g_orange;
int g_red;
int g_white;
int **g_map;

typedef struct	s_cub
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		r[2];
	int		f[3];
	int		c[3];
	int		**map;
}				t_map;

typedef struct	s_cublist
{
	float	p_x;
	float	p_y;
	int		rot;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_cub;

/*
**	Display fonctions
*/

void	ft_square(t_cub *var, int color);
void	ft_line(int color, t_cub *var, float rot);

/*
** Info fonctions
*/

void	ft_info(t_map *info);
char	*ft_get_info(char *line, int i);
void	ft_get_resolution(t_map *info, char *line);
void	ft_get_color_f(t_map *info, char *line);
void	ft_get_color_c(t_map *info, char *line);

/*
** Key fonctions
*/

int ft_go(int key, t_cub *var);

/*
** Map fonctions
*/

void	ft_reset(void *mlx_ptr, void *win_ptr);
void	ft_map(t_cub var);
void	ft_wall(t_cub var, int wall, int x, int y);
int		ft_is_wall(int x, int y);

/*
** Movement fonctions
*/

void	ft_go_w(t_cub *var);
void	ft_go_a(t_cub *var);
void	ft_go_s(t_cub *var);
void	ft_go_d(t_cub *var);

/*
** Rotation fonctions
*/

void	ft_look_right(t_cub *var);
void	ft_look_left(t_cub *var);

/*
** Utils fonctions
*/

void	ft_color_init(void);

#endif
