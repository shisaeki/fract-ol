/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:24:51 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/12 23:39:06 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract-ol.h"

int	main(void)
{
	t_vars	vars;

	vars.mlx.mlx_ptr = mlx_init();
	vars.mlx.win = mlx_new_window(vars.mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	vars.img.img_ptr = mlx_new_image(vars.mlx.mlx_ptr, IMG_SIZE, IMG_SIZE);
	vars.img.data = (int *)mlx_get_data_addr(
		vars.img.img_ptr,
		&vars.img.bpp,
		&vars.img.size_l,
		&vars.img.endian
	);
	mlx_key_hook(vars.mlx.win, key_events, &vars);
	draw_mandelbrot(&vars);
	mlx_loop(vars.mlx.mlx_ptr);
}