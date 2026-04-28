/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:14:56 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/28 15:25:16 by ldesboui         ###   ########.fr       */
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

void	init_player_pos(t_game *game, int x, int y)
{
	int	count;

	count = 0;
	if (!game->map)
		return ;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("NSEW", game->map[y][x]))
			{
				set_orientation(game, x, y);
				++count;
			}
			++x;
		}
		y++;
	}
	if (count != 1)
	{
		printf("Error\nThere is a problem with player position\n");
		free_mlx(game);
		exit(0);
	}
}
