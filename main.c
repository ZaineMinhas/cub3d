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

void ft_square(t_cublist *var)
{
	int i;
	int j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			mlx_pixel_put(var->mlx_ptr, var->win_ptr, var->p_x + i, var->p_y + j, g_rose);
	}
}

void ft_go_up(t_cublist *var)
{
	var->p_y -= 5;
	ft_square(var);
}

void ft_go_left(t_cublist *var)
{
	var->p_x -= 5;
	ft_square(var);
}

void ft_go_down(t_cublist *var)
{
	var->p_y += 5;
	ft_square(var);
}

void ft_go_right(t_cublist *var)
{
	var->p_x += 5;
	ft_square(var);
}

int ft_go(int key, t_cublist *var)
{
	if (key == 53)
		exit(1);
	else if (key == 13 /*w*/)
		ft_go_up(var);
	else if (key == 0 /*a*/)
		ft_go_left(var);
	else if (key == 1 /*s*/)
		ft_go_down(var);
	else if (key == 2 /*d*/)
		ft_go_right(var);
	// else if (key == 123 /*left*/)
	// 	ft_look_left(var);
	// else if (key == 124 /*right*/)
	// 	ft_look_right(var);
	return (0);
}

int main(void)
{
	t_cublist var;

	var.p_x = 1920 / 2;
	var.p_y = 1080 / 2;
	var.mlx_ptr = mlx_init();
	var.win_ptr = mlx_new_window(var.mlx_ptr, 1920, 1080, "la fenetre");
	//ft_reset(var.mlx_ptr, var.win_ptr);
	ft_square(&var);
	mlx_key_hook(var.win_ptr, ft_go, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

// w = 13, a = 0, s = 1, d = 2, up = 126, left = 123, right = 124, down = 125

// la commande : gcc -lmlx -framework OpenGL -framework AppKit main.c && clear && ./a.out 