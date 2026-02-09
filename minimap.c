/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:54:19 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/09 22:42:56 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_fov(t_game *game, int size, int offset)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	x = (double)(size / 2 + offset);
	y = (double)(size / 2 + offset);
	while (i < 5)
	{
		x += cos(game->player_angle - (M_PI / 6));
		y += sin(game->player_angle - (M_PI / 6));
		my_mlx_pixel_put(game, (int)x, (int)y, 10);
		++i;
	}
	i = 0;
	x = (double)(size / 2 + offset);
	y = (double)(size / 2 + offset);
	while (i < 5)
	{
		x += cos(game->player_angle + (M_PI / 6));
		y += sin(game->player_angle + (M_PI / 6));
		my_mlx_pixel_put(game, (int)x, (int)y, 10);
		++i;
	}
}

void	draw_cursor(t_game *game, int offset, int size)
{
	my_mlx_pixel_put(game, size / 2 + offset, size / 2 + offset, 0);
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
