#include "minilibx-linux/mlx.h"
#include <stdio.h>

#define WIN_SIZE 800
#define IMG_SIZE 800

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
}		t_mlx;

typedef struct	s_img
{
	void	*img_ptr;
	int	*data;
	int	size_l;
	int	bpp;
	int	endian;
}		t_img;

typedef struct	s_vars
{
	t_mlx	mlx;
	t_img	img;
}		t_vars;

int draw_mandelbrot(t_vars *vars)
{
	int	w, h;
	float	x, y;
	float	a, b;

	h = 0;
	while (h < IMG_SIZE)
	{
		w = 0;
		while (w < IMG_SIZE)
		{
			x = (float)(w - IMG_SIZE / 2) * 4 / (float)IMG_SIZE;
			y = (float)(h - IMG_SIZE / 2) * (-4)/ (float)IMG_SIZE;
			a = 0;
			b = 0;
			for (int i = 0; i < 50; i++)
			{
				float tmp_a = a * a - b * b + x;
				float tmp_b = 2 * a * b + y;
				a = tmp_a;
				b = tmp_b;
				if (a * a + b * b > 4)
				{
					vars->img.data[h * IMG_SIZE + w] = 0X000101 * (i * 5);
					break;
				}	
			}
			w++;	
		}
		h++;
	}
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win, vars->img.img_ptr, 0, 0);
	return (0);
}

int draw_julia(t_vars *vars)
{
	int	w, h;
	float	x, y;
	float	c_x, c_y;
	float	a, b;

	c_x = -0.8;
	c_y = 0.156;
	h = 0;
	while (h < IMG_SIZE)
	{
		w = 0;
		while (w < IMG_SIZE)
		{

			x = (float)(w - IMG_SIZE / 2) * 4 / (float)IMG_SIZE;
			y = (float)(h - IMG_SIZE / 2) * (-4)/ (float)IMG_SIZE;
			a = x;
			b = y;
			for (int i = 0; i < 100; i++)
			{
				float tmp_a = a * a - b * b + c_x;
				float tmp_b = 2 * a * b + c_y;
				a = tmp_a;
				b = tmp_b;
				if (a * a + b * b > 4)
				{
					vars->img.data[h * IMG_SIZE + w] = 0X000101 * (i * 5);
					break;
				}
			}
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win, vars->img.img_ptr, 0, 0);
	return (0);
}

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
