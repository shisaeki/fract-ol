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

int draw_fractol(t_vars *vars)
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
//			vars->img.data[h * IMG_SIZE + w] = 0XFFFFFF;
//			w++;
			x = (float)(w - IMG_SIZE / 2) / (float)IMG_SIZE;
			y = (float)((h - IMG_SIZE / 2) / (float)IMG_SIZE) * (-1);
			a = 0;
			b = 0;
			for (int i = 0; i < 50; i++)
			{
				a = a * a - b * b + x;
				b = 2 * a * b + y;
				if (a * a + b * b > 4)
				{
					vars->img.data[h * IMG_SIZE + w] = 0XFFFFFF;
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
	draw_fractol(&vars);
	mlx_loop(vars.mlx.mlx_ptr);

	return (0);
}
