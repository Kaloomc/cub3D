/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:58:40 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/27 01:00:10 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_wall_info(t_wall_info *w, double dist)
{
	double	plan_dist;

	plan_dist = (SCREEN_W / 2.0) / tan(M_PI / 6.0);
	if (dist < 0.0001)
		dist = 0.0001;
	w->line_height = (int)(plan_dist / dist);
	w->draw_start = -w->line_height / 2 + SCREEN_H / 2;
	if (w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_height / 2 + SCREEN_H / 2;
	if (w->draw_end >= SCREEN_H)
		w->draw_end = SCREEN_H - 1;
	w->step = 1.0 * 64 / w->line_height;
	w->tex_pos = (w->draw_start - SCREEN_H / 2 + w->line_height / 2) * w->step;
}

static void	draw_background(t_game *game, int x, int draw_start, int draw_end)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		my_mlx_pixel_put(game, x, y, game->ceiling_color);
		y++;
	}
	y = draw_end;
	while (y < SCREEN_H)
	{
		my_mlx_pixel_put(game, x, y, game->floor_color);
		y++;
	}
}

static void	draw_pixels(t_game *game, t_draw_tex *args, t_wall_info *w)
{
	int				y;
	int				tex_y;
	unsigned int	color;
	char			*src;

	y = w->draw_start;
	while (y < w->draw_end)
	{
		tex_y = (int)w->tex_pos & (64 - 1);
		w->tex_pos += w->step;
		src = args->tex->addr + (tex_y * args->tex->line_len + args->tex_x
				* (args->tex->bits_per_pixel / 8));
		color = *(unsigned int *)src;
		my_mlx_pixel_put(game, args->x, y, color);
		y++;
	}
}

void	draw_wall_texture(t_game *game, t_draw_tex *args)
{
	t_wall_info	w;

	init_wall_info(&w, args->dist);
	draw_background(game, args->x, w.draw_start, w.draw_end);
	draw_pixels(game, args, &w);
}
