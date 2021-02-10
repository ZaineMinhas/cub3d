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
	int color;
	int i;
	int j;

	if (wall)
		color = g_orange;
	else
		color = 0;
	i = -1;
	while (++i < 100)
	{
		j = -1;
		while (++j < 107)
			mlx_pixel_put(var.mlx_ptr, var.win_ptr, x * 101 + i, y * 108 + j, color);
	}
}

void ft_map(t_cublist var)
{
	int i;
	int j;
	int map_x;
	int map_y;
	int map[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
				1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
				1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
				1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
				1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
				1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	map_x = 19;
	map_y = 10;
	i = -1;
	while (++i < map_x)
	{
		j = -1;
		while (++j < map_y)
			ft_wall(var, map[j * map_x + i], i, j);
	}


}

void ft_square(t_cublist *var, int color)
{
	float dx;
	float dy;
	float x;
	float y;
	int i;

	dx = cos(var->rot * (M_PI / 180));
	dy = sin(var->rot * (M_PI / 180));
	i = -1;
	while (++i < 15)
	{
		x = -1;
		while (++x < 15)
			mlx_pixel_put(var->mlx_ptr, var->win_ptr, var->p_x + i, var->p_y + x, color);
	}
	i = -1;
	x = 0;
	y = 0;
	if (color)
		color = g_red;
	while (++i < 40)
	{
		x += dx;
		y += dy;
		mlx_pixel_put(var->mlx_ptr, var->win_ptr, x + var->p_x, var->p_y - y, color);
	}
}

void ft_go_w(t_cublist *var)
{
	float dx;
	float dy;

	ft_square(var, 0);
	dx = cos(var->rot);
	dy = sin(var->rot);
	var->p_x -= dx;
	var->p_y -= dy;
	ft_square(var, g_rose);
}

void ft_go_a(t_cublist *var)
{
	float dx;
	float dy;

	ft_square(var, 0);
	dx = cos((M_PI / 180) * var->rot * 10);
	dy = sin((M_PI / 180) * var->rot * 10);
	var->p_x -= dy;
	var->p_x += dx;
	ft_square(var, g_rose);
}

void ft_go_s(t_cublist *var)
{
	float dx;
	float dy;
	ft_square(var, 0);
	var->p_x += dx;
	var->p_y += dy;
	ft_square(var, g_rose);
}

void ft_go_d(t_cublist *var)
{
	float dx;
	float dy;

	ft_square(var, 0);
	dx = cos((M_PI / 180) * var->rot * 10);
	dy = sin((M_PI / 180) * var->rot * 10);
	var->p_x += dy;
	var->p_y -= dx;
	ft_square(var, g_rose);
}

void ft_look_right(t_cublist *var)
{
	ft_square(var, 0);
	var->rot -= 15;
	var->rot %= 360;
	ft_square(var, g_rose);
}

void ft_look_left(t_cublist *var)
{
	ft_square(var, 0);
	var->rot += 15;
	var->rot %= 360;
	ft_square(var, g_rose);
}

void ft_go_rot(t_cublist *var, int key)
{
	if (!var->rot)
	{
		if (key == 13 /*w*/)
			ft_go_up(var);
		else if (key == 0 /*a*/)
			ft_go_left(var);
		else if (key == 1 /*s*/)
			ft_go_down(var);
		else if (key == 2 /*d*/)
			ft_go_right(var);
	}
	else if (var->rot == 1)
	{
		if (key == 13 /*w*/)
			ft_go_right(var);
		else if (key == 0 /*a*/)
			ft_go_up(var);
		else if (key == 1 /*s*/)
			ft_go_left(var);
		else if (key == 2 /*d*/)
			ft_go_down(var);
	}
	else if (var->rot == 2)
	{
		if (key == 13 /*w*/)
			ft_go_down(var);
		else if (key == 0 /*a*/)
			ft_go_right(var);
		else if (key == 1 /*s*/)
			ft_go_up(var);
		else if (key == 2 /*d*/)
			ft_go_left(var);
	}
	else if (var->rot == 3)
	{
		if (key == 13 /*w*/)
			ft_go_left(var);
		else if (key == 0 /*a*/)
			ft_go_down(var);
		else if (key == 1 /*s*/)
			ft_go_right(var);
		else if (key == 2 /*d*/)
			ft_go_up(var);
	}
}

int ft_go(int key, t_cublist *var)
{
	if (key == 53 /*esc*/)
		exit(1);
	else if (key == 123 /*left*/)
		ft_look_left(var);
	else if (key == 124 /*right*/)
		ft_look_right(var);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		ft_go_rot(var, key);
	return (0);
}

int main(void)
{
	t_cublist var;

	var.p_x = 1920 / 2;
	var.p_y = 1080 / 2;
	var.rot = 90;
	var.mlx_ptr = mlx_init();
	var.win_ptr = mlx_new_window(var.mlx_ptr, 1920, 1080, "la fenetre");
	//ft_reset(var.mlx_ptr, var.win_ptr);
	ft_map(var);
	ft_square(&var, g_rose);
	mlx_key_hook(var.win_ptr, ft_go, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

// w = 13, a = 0, s = 1, d = 2, up = 126, left = 123, right = 124, down = 125

// la commande : gcc -lmlx -framework OpenGL -framework AppKit main.c && clear && ./a.out