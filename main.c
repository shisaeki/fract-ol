#include "minilibx-linux/mlx.h"
#include "fract-ol.h"

int main()
{
	t_vars	vars;

	vars.mlx.mlx_ptr = mlx_init();
	vars.mlx.win = mlx_new_window(vars.mlx.mlx_ptr, WIN_SIZE, WIN_SIZE, "fractol");
	vars.img.img_ptr = mlx_new_image(vars.mlx.mlx_ptr, IMG_SIZE, IMG_SIZE);
	vars.img.data = (int *)mlx_get_data_addr(vars.img.img_ptr, &vars.img.bpp, &vars.img.size_l, &vars.img.endian);
	draw_julia(&vars);
	mlx_loop(vars.mlx.mlx_ptr);

	return (0);
}
