/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:51:56 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/12 23:39:28 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract-ol.h"

int	draw_mandelbrot(t_vars *vars)
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
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win, vars->img.img_ptr, (WIN_WIDTH - IMG_SIZE) / 2, (WIN_HEIGHT - IMG_SIZE) / 2);
	return (0);
}