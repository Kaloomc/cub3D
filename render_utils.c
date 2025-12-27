/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:56:23 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/27 01:31:29 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_square_put(t_game *game, int x, int y, int color)
{
	int	tmp_x;
	int	tmp_y;

	tmp_y = y;
	while (tmp_y < y + SCREEN_H / game->map_y)
	{
		tmp_x = x;
		while (tmp_x < x + SCREEN_W / game->map_x)
		{
			my_mlx_pixel_put(game, tmp_x, tmp_y, color);
			tmp_x++;
		}
		tmp_y++;
	}
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= SCREEN_W || y >= SCREEN_H)
		return ;
	dst = game->img.addr + (y * game->img.line_len + x
			* (game->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
