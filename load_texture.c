/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:18:04 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/05 15:32:43 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *game, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->line_len,
			&tex->endian);
	if (!tex->img)
	{
		printf("Error\nImpossible de charger la texture : %s\n", path);
		free(path);
		free_mlx(game);
	}
	free(path);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_len, &tex->endian);
}

void	init_assets(t_game *game)
{
	init_texture(game, &game->tex_north, ft_strtrim(game->paths[0], " \n"));
	init_texture(game, &game->tex_south, ft_strtrim(game->paths[1], " \n"));
	init_texture(game, &game->tex_east, ft_strtrim(game->paths[2], " \n"));
	init_texture(game, &game->tex_west, ft_strtrim(game->paths[3], " \n"));
}
