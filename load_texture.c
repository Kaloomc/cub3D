/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:18:04 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/27 01:46:55 by fgarnier         ###   ########.fr       */
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
		free_mlx(game);
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_len, &tex->endian);
}

void	init_assets(t_game *game)
{
	init_texture(game, &game->tex_north, "./textures/NO.xpm");
	init_texture(game, &game->tex_south, "./textures/SO.xpm");
	init_texture(game, &game->tex_east, "./textures/EA.xpm");
	init_texture(game, &game->tex_west, "./textures/WE.xpm");
	game->floor_color = 0x00333333;
	game->ceiling_color = 0x0087CEEB;
}
