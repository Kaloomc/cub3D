/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:54:19 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/09 14:14:47 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_cursor(t_game *game, int offset, int size)
{
	my_mlx_pixel_put(game, size / 2 + offset, size / 2 + offset, 0);
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
