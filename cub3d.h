/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:36:23 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/27 01:38:47 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CUBE3D
# define H_CUBE3D

# define SCREEN_H 800
# define SCREEN_W 800

# define SPEED 0.05
# define M_PI 3.14159265358979323846

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_draw_tex
{
	int			x;
	int			tex_x;
	double		dist;
	t_img		*tex;
}				t_draw_tex;

typedef struct s_wall_info
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		step;
	double		tex_pos;
}				t_wall_info;

typedef struct s_ray
{
	int			map_x;
	int			map_y;
	double		dir_x;
	double		dir_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
	int			side;
}				t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;

	char		**map;
	int			map_x;
	int			map_y;

	double		player_x;
	double		player_y;
	double		player_angle;

	t_img		tex_north;
	t_img		tex_south;
	t_img		tex_east;
	t_img		tex_west;

	int			floor_color;
	int			ceiling_color;

	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;

	int			key_right;
	int			key_left;

	long long	last_update;

	t_img		img;
}				t_game;

// map
void			get_map(char *file_name, t_game *game);

// render utils
void			my_mlx_pixel_put(t_game *game, int x, int y, int color);
void			my_mlx_square_put(t_game *game, int x, int y, int color);

// load_texture
void			init_assets(t_game *game);

// render
void			render_map(t_game *game);
void			render_player(t_game *game);

// graphic
void			graphic_update(t_game *game);

// player
void			move(t_game *game);
int				is_valid_pos(t_game *game, double x, double y);
void			init_player_pos(t_game *game);

// dda
void			perform_dda(t_game *game, t_ray *ray);

// keyboard
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);

// draw
void			draw_wall_texture(t_game *game, t_draw_tex *args);

// raycast
double			shoot_ray(t_game *game, double angle, int *side_ret);
void			raycast(t_game *game);
// utils.c
long long		get_time(void);

// free
void			free_mlx(t_game *game);

#endif