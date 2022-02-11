/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:37:45 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/11 17:35:39 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
**		-___STRUCT___-
*/

typedef struct s_player
{
}				t_player;

typedef struct s_map
{
	int		resolution[2];
	char	**map;
	char	**info;
}				t_map;

typedef struct s_img
{
	char	*addr;
	void	*img;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
}				t_img;

typedef struct s_cub
{
	t_player	*p1;
	t_map		*map;
	t_img		*img;
}				t_cub;

/*
**		-___INIT___-
*/

int	init_var(t_cub *cub);

/*
**		-___PARSING___-
*/

int	parse(char **argv, t_cub *cub);
int	check_args(int argc, char **argv);

/*
**		-___UTILS___-
*/

int	free_all(t_cub *cub);
void	free_double_char(char **str);

/*
**		-___UTILS___-
*/

int	ft_is_white_space(char c);

#endif