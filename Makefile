all:
	gcc -o fractol main.c mandelbrot.c julia.c minilibx-linux/libmlx_Linux.a -lXext -lX11
