/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:18:04 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/28 16:18:04 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *game, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->line_len,
			&tex->endian);
	if (!tex->img)
	{
		printf("Error\nFailed to load texture : %s\n", path);
		free_mlx(game);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_len, &tex->endian);
}

void	init_assets(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!game->paths[i])
		{
			printf("Error\nA texture path is missing\n");
			free_mlx(game);
			exit(1);
		}
		game->paths[i] = ft_strtrim(game->paths[i], " \n");
		i++;
	}
	game->paths[0] = ft_strtrim(game->paths[0], " \n");
	init_texture(game, &game->tex_north, game->paths[0]);
	game->paths[1] = ft_strtrim(game->paths[1], " \n");
	init_texture(game, &game->tex_south, game->paths[1]);
	game->paths[2] = ft_strtrim(game->paths[2], " \n");
	init_texture(game, &game->tex_east, game->paths[2]);
	game->paths[3] = ft_strtrim(game->paths[3], " \n");
	init_texture(game, &game->tex_west, game->paths[3]);
}
