/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:54:19 by fgarnier          #+#    #+#             */
/*   Updated: 2026/03/17 16:39:08 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->addr
		+ (y * img->line_len + x * (img->bits_per_pixel / 8))));
}

static void	draw_fov(t_game *game, int size, int offset)
{
	double	x;
	double	y;

	x = (double)(size / 2 + offset);
	y = (double)(size / 2 + offset);
	while (x > 25 && y > 25 && x < 225 && y < 225 && get_pixel(&(game->img), x, y) != 0)
	{
		my_mlx_pixel_put(game, (int)x, (int)y, 10);
		x += cos(game->player_angle - (M_PI / 6));
		y += sin(game->player_angle - (M_PI / 6));
	}
	x = (double)(size / 2 + offset);
	y = (double)(size / 2 + offset);
	while (x > 25 && y > 25 && x < 225 && y < 225 && get_pixel(&(game->img), x, y) != 0)
	{
		my_mlx_pixel_put(game, (int)x, (int)y, 10);
		x += cos(game->player_angle + (M_PI / 6));
		y += sin(game->player_angle + (M_PI / 6));
	}
}

void	draw_cursor(t_game *game, int offset, int size)
{
	my_mlx_pixel_put(game, size / 2 + offset, size / 2 + offset, 16777215);
	draw_fov(game, size, offset);
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;
	int	size;
	int	offset;

	size = 200;
	offset = 25;
	x = 0;
	while (x < size + offset)
	{
		y = 0;
		while (y < size + offset)
		{
			if (is_valid_pos(game, (game->player_x + ((double)x - (size / 2.0))
						/ game->minimap_zoom), (game->player_y + ((double)y
							- (size / 2.0)) / game->minimap_zoom)))
				my_mlx_pixel_put(game, x + offset, y + offset, 16777215);
			else
				my_mlx_pixel_put(game, x + offset, y + offset, 0);
			y++;
		}
		x++;
	}
	draw_cursor(game, offset, size);
}
