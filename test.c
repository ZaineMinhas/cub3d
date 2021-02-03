#include "cub3d.h"

void	ft_reset(void *ptr, void *ptr2)
{
	int	j;
	int	i;

	i = -1;
	j = -1;
	while (++i < 1921)
	{
		j = -1;
		while (++j < 1081)
			mlx_pixel_put(ptr, ptr2, i, j, 075255001);
	}
}

void	go_up(void *param)
{
	ft_reset(param.ptr, param.ptr2);

}

void	*key_hook(int key_code, void *param)
{
	if (key_code == 'w')
		go_up(param);
	else if (key_code == 's')
		go_down(param);
	else if (key_code == 'a')
		go_left(param);
	else if (key_code == 'd')
}

void	ft_set_param(t_cub3dlist param)
{
	param.weight = 20;
	param.p_x = 960 - param.weight / 2;
	param.p_y = 540 - param.weight / 2;
}

int	main()
{
	int 		x;
	int			y;
	t_cub3dlist	param;

	ft_set_param(param);
	param.ptr = mlx_init();
	param.ptr2 = mlx_new_window(param.ptr, 1920, 1080, "la fenetre");
	ft_reset(param.ptr, param.ptr2);
	mlx_key_hook(param.ptr2, &key_hook, &param);
	mlx_loop(param.ptr);
	return (0);
	
}

// gcc -lmlx -framework OpenGL -framework AppKit test.c