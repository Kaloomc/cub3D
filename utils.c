/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:14:56 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/05 15:13:59 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	set_orientation(t_game *game, int x, int y)
{
	game->player_x = x + 0.5;
	game->player_y = y + 0.5;
	if (game->map[y][x] == 'N')
		game->player_angle = 3 * M_PI / 2;
	else if (game->map[y][x] == 'S')
		game->player_angle = M_PI / 2;
	else if (game->map[y][x] == 'E')
		game->player_angle = 0;
	else if (game->map[y][x] == 'W')
		game->player_angle = M_PI;
	game->map[y][x] = '0';
	return ;
}

void	init_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("NSEW", game->map[y][x]))
			{
				set_orientation(game, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}
