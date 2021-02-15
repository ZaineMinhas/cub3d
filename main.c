#include <stdio.h>
#include "cub3d.h"

void ft_reset(void *mlx_ptr, void *win_ptr)
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

void ft_wall(t_cublist var, int wall, int x, int y)
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
			mlx_pixel_put(var.mlx_ptr, var.win_ptr, x * 100 + i + 1, y * 100 + j + 1, g_orange);
	}
}

void ft_map(t_cublist var)
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

int	ft_is_wall(int x, int y)
{
	if (g_map[y / 100][x / 100])
		return (1);
	return (0);
}

void ft_line(int color, t_cublist *var, float rot)
{
	float dx;
	float dy;
	int i;

	i = -1;
	dx = 0;
	dy = 0;
	while (++i < 2225 && !ft_is_wall(var->p_x + dx, var->p_y - dy))
	{
		dx += cos(((float)var->rot + rot) * (M_PI / 180));
		dy += sin(((float)var->rot + rot) * (M_PI / 180));
		mlx_pixel_put(var->mlx_ptr, var->win_ptr, dx + var->p_x, var->p_y - dy, color);
	}
}

void ft_square(t_cublist *var, int color)
{
	float x;
	float y;
	float i;

	i = -1;
	while (++i < 6)
	{
		x = -1;
		while (++x < 6)
			mlx_pixel_put(var->mlx_ptr, var->win_ptr, var->p_x + i - 3, var->p_y + x - 3, color);
	}
	if (color)
		color = g_white;
	i = -45;
	while (i < 46)
	{
		i += 1;
		ft_line(color, var, i);
	}
}

void ft_go_w(t_cublist *var)
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

void ft_go_a(t_cublist *var)
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

void ft_go_s(t_cublist *var)
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

void ft_go_d(t_cublist *var)
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

void ft_look_right(t_cublist *var)
{
	ft_square(var, 0);
	var->rot -= 5;
	var->rot %= 360;
	ft_square(var, g_rose);
}

void ft_look_left(t_cublist *var)
{
	ft_square(var, 0);
	var->rot += 5;
	var->rot %= 360;
	ft_square(var, g_rose);
}


int ft_go(int key, t_cublist *var)
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

int main(void)
{
	t_cublist var;

	var.p_x = 1920 / 3;
	var.p_y = 1080 / 2;
	var.rot = 90;
	var.mlx_ptr = mlx_init();
	var.win_ptr = mlx_new_window(var.mlx_ptr, 1920, 1080, "la fenetre");
	//ft_reset(var.mlx_ptr, var.win_ptr);
	ft_map(var);
	ft_square(&var, g_rose);
	mlx_hook(var.win_ptr, 2, 1L<<0, ft_go, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

// w = 13, a = 0, s = 1, d = 2, up = 126, left = 123, right = 124, down = 125

// la commande : gcc -lmlx -framework OpenGL -framework AppKit main.c && clear && ./a.out