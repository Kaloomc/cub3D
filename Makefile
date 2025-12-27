# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 16:32:12 by fgarnier          #+#    #+#              #
#    Updated: 2025/12/27 16:20:14 by fgarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

# --- CONFIG LIBFT ---
LIBFT_PATH = ./libft
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

# --- CONFIG MLX ---
MLX_PATH = ./mlx
OBJ_DIR = obj

# VERSION LINUX
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

# --- CONFIG GNL ---
GNL_PATH = ./gnl
GNL_SRC = $(GNL_PATH)/get_next_line.c \
          $(GNL_PATH)/get_next_line_utils.c

# --- FICHIERS ---
# J'ai rajouté map.c ici car il est nécessaire pour ton main
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
      $(GNL_SRC)

# Génère les chemins des objets (ex: obj/main.o, obj/gnl/get_next_line.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# --- REGLES ---

all: $(NAME)

# 1. Compilation des objets
# J'ai ajouté -I$(GNL_PATH) pour trouver le .h de GNL
$(OBJ_DIR)/%.o: %.c cub3d.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT_PATH) -I$(GNL_PATH) -c $< -o $@

# 2. Linkage final
$(NAME): $(OBJ)
	@echo "Compilation de la MLX..."
	@make -C $(MLX_PATH) > /dev/null 2>&1
	@echo "Compilation de la Libft..."
	@make -C $(LIBFT_PATH)
	@echo "Compilation de Cub3D..."
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(MLX_PATH) clean > /dev/null
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re