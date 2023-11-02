all:
	gcc -o fractol main.c minilibx-linux/libmlx_Linux.a -lXext -lX11
