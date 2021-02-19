#include "cub3d.h"

int main(void)
{
	t_cub var;
	//t_map info;

	//ft_info(&info);
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

// la commande : gcc -lmlx -framework OpenGL -framework AppKit cub3d.a && clear && ./a.out