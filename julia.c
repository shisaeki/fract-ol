#include "fract-ol.h"

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
