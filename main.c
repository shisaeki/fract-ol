/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:27:43 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/01/12 17:38:38 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (0);
	vars.mlx.mlx_ptr = mlx_init();
	vars.mlx.win = mlx_new_window(vars.mlx.mlx_ptr, WIN_SIZE, WIN_SIZE, "fractol");
	vars.img.img_ptr = mlx_new_image(vars.mlx.mlx_ptr, IMG_SIZE, IMG_SIZE);
	vars.img.data = (int *)mlx_get_data_addr(
		vars.img.img_ptr,
		&vars.img.bpp,
		&vars.img.size_l,
		&vars.img.endian
	);
	if (argv[1] == "mandelbrot")
		draw_mandelbrot(&vars);
	else
		draw_julia(&vars);
	mlx_loop(vars.mlx.mlx_ptr);
	return (0);
}
