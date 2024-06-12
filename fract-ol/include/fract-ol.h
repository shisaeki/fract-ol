/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:58:21 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/11 23:58:21 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H

# include "../../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define WIN_WIDTH 720
# define WIN_HEIGHT 720
# define IMG_SIZE 720

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
}				t_mlx;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_vars
{
	t_mlx	mlx;
	t_img	img;
}				t_vars;


int	key_events(int keycode, t_vars *vars);
int	draw_mandelbrot(t_vars *vars);
int	draw_julia(t_vars *vars);

#endif