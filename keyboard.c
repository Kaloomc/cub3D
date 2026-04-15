/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:57:40 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/15 14:24:20 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65453 && game->minimap_zoom > 1)
		game->minimap_zoom -= 1;
	if (keycode == 65451)
		game->minimap_zoom += 1;
	if (keycode == 119)
		game->key_w = 1;
	if (keycode == 97)
		game->key_a = 1;
	if (keycode == 115)
		game->key_s = 1;
	if (keycode == 100)
		game->key_d = 1;
	if (keycode == 65361)
		game->key_left = 1;
	if (keycode == 65363)
		game->key_right = 1;
	if (keycode == 65307)
		free_mlx(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key_w = 0;
	if (keycode == 97)
		game->key_a = 0;
	if (keycode == 115)
		game->key_s = 0;
	if (keycode == 100)
		game->key_d = 0;
	if (keycode == 65361)
		game->key_left = 0;
	if (keycode == 65363)
		game->key_right = 0;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	int	delta_x;

	(void)y;
	delta_x = x - (SCREEN_W / 2);
	if (delta_x != 0)
	{
		game->player_angle += delta_x * MOUSE_SENS;
		if (game->player_angle < 0)
			game->player_angle += 2 * M_PI;
		if (game->player_angle > 2 * M_PI)
			game->player_angle -= 2 * M_PI;
		mlx_mouse_move(game->mlx, game->win, SCREEN_W / 2, SCREEN_H / 2);
	}
	return (0);
}
