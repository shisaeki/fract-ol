# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 22:34:14 by shinsaeki         #+#    #+#              #
#    Updated: 2024/06/11 23:54:02 by shinsaeki        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = fract-ol

SRC_DIR = src

SRC_FILES = $(SRC_DIR)/main.c \
			$(SRC_DIR)/events.c \
			$(SRC_DIR)/mandelbrot.c \
			$(SRC_DIR)/julia.c

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) -g $(SRC_FILES) -I../minilibx-linux -L../minilibx-linux -L/opt/X11/lib -I/opt/X11/include -lmlx -lXext -lX11 -lm

clean:
	rm -f $(TARGET)