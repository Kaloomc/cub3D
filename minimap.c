/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:54:19 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/07 03:02:04 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_cursor(t_game *game, int offset, int size)
{
	// cursor
	(void)game;
	(void)offset;
	(void)size;
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
						/ 10.0), (game->player_y + ((double)y - (size / 2.0))
						/ 10.0)))
				my_mlx_pixel_put(game, x + offset, y + offset, 16777215);
			else
				my_mlx_pixel_put(game, x + offset, y + offset, 0);
			y++;
		}
		x++;
	}
	draw_cursor(game, offset, size);
}
