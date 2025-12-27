/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 01:32:51 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/27 14:45:22 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_image_if(t_game *game, void **img)
{
	if (!game || !img || !*img)
		return ;
	if (game->mlx)
		mlx_destroy_image(game->mlx, *img);
	*img = NULL;
}

void	free_texture(t_game *game)
{
	destroy_image_if(game, &game->tex_north.img);
	destroy_image_if(game, &game->tex_west.img);
	destroy_image_if(game, &game->tex_east.img);
	destroy_image_if(game, &game->tex_south.img);
	destroy_image_if(game, &game->img.img);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_mlx(t_game *game)
{
	free_texture(game);
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
