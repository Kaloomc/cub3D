# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 16:32:12 by fgarnier          #+#    #+#              #
#    Updated: 2026/04/28 18:24:08 by fgarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_PATH = ./libft
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

MLX_PATH = ./mlx
OBJ_DIR = obj

MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

GNL_PATH = ./gnl
GNL_SRC = $(GNL_PATH)/get_next_line.c \
          $(GNL_PATH)/get_next_line_utils.c

SRC = main.c \
      render_utils.c \
      keyboard.c \
      utils.c \
      player.c \
      graphic.c \
      render.c \
      map.c \
	  raycast.c \
	  draw.c \
	  load_texture.c \
	  dda.c \
	  free.c \
	  parsing.c\
	  parsing_utils.c \
	  flood_fill.c \
	  minimap.c \
      $(GNL_SRC)

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c cub3d.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT_PATH) -I$(GNL_PATH) -c $< -o $@

$(NAME): $(MLX_PATH) $(OBJ)
	@echo "MLX Compilation..."
	@make -C $(MLX_PATH) > /dev/null 2>&1
	@echo "Libft Compilation..."
	@make -C $(LIBFT_PATH)
	@echo "Cub3D Compilation..."
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(MLX_PATH):
	@echo "MinilibX..."
	git clone https://github.com/42paris/minilibx-linux.git $(MLX_PATH)

clean:
	rm -rf $(OBJ_DIR)
	@if [ -d "$(MLX_PATH)" ]; then make -C $(MLX_PATH) clean > /dev/null; fi
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_PATH)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
