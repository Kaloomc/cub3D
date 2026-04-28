/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:07:19 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/07 01:10:55 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	graphic_update(t_game *game)
{
	ft_bzero(game->img.addr, SCREEN_H * game->img.line_len);
	raycast(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
