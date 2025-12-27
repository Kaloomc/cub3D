/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:56:16 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/27 01:32:34 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_pos(t_game *game, double x, double y)
{
	int	real_x;
	int	real_y;

	real_x = (int)x;
	real_y = (int)y;
	if (real_x < 0 || real_x >= game->map_x || real_y < 0
		|| real_y >= game->map_y)
		return (0);
	if (game->map[real_y][real_x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *game, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + move_x;
	if (is_valid_pos(game, new_x, game->player_y))
		game->player_x = new_x;
	new_y = game->player_y + move_y;
	if (is_valid_pos(game, game->player_x, new_y))
		game->player_y = new_y;
}

void	player_dir(t_game *game, double move_x, double move_y)
{
	if (game->key_w)
	{
		move_x += cos(game->player_angle) * SPEED;
		move_y += sin(game->player_angle) * SPEED;
	}
	if (game->key_s)
	{
		move_x -= cos(game->player_angle) * SPEED;
		move_y -= sin(game->player_angle) * SPEED;
	}
	if (game->key_a)
	{
		move_x += cos(game->player_angle - M_PI / 2) * SPEED;
		move_y += sin(game->player_angle - M_PI / 2) * SPEED;
	}
	if (game->key_d)
	{
		move_x += cos(game->player_angle + M_PI / 2) * SPEED;
		move_y += sin(game->player_angle + M_PI / 2) * SPEED;
	}
	move_player(game, move_x, move_y);
}

void	move(t_game *game)
{
	if (game->key_left)
		game->player_angle -= 0.05;
	if (game->key_right)
		game->player_angle += 0.05;
	if (game->player_angle < 0)
		game->player_angle += 2 * M_PI;
	if (game->player_angle > 2 * M_PI)
		game->player_angle -= 2 * M_PI;
	player_dir(game, 0, 0);
}
