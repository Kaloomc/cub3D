/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/26 18:03:48 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map[y][x] == '1')
				my_mlx_square_put(game, x * (SCREEN_W / game->map_x), y
					* (SCREEN_H / game->map_y), 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	my_mlx_pixel_put(game, game->player_x, game->player_y, 0x00FF0000);
}
