/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:28:11 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/01/12 17:36:26 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"

# define WIN_SIZE 800
# define IMG_SIZE 800

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

int	draw_mandelbrot(t_vars *vars);
int	draw_julia(t_vars *vars);

#endif
