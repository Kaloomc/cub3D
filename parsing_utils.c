/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:47:34 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/28 16:15:56 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	color_exit(char *line, t_game *game, int fd)
{
	close(fd);
	printf("Error\nInvalid Color\n");
	free(line);
	get_next_line(-1);
	free_mlx(game);
}

void	get_color(char *line, t_game *game, int fd)
{
	if ((line[0] == 'C' && game->ceiling_color != -1) || (line[0] == 'F'
			&& game->floor_color != -1))
	{
		color_exit(line, game, fd);
		return ;
	}
	if (line[0] == 'C')
	{
		game->ceiling_color = convert_rgb(line);
		if (game->ceiling_color != -1)
			return ;
	}
	if (line[0] == 'F')
	{
		game->floor_color = convert_rgb(line);
		if (game->floor_color != -1)
			return ;
	}
	color_exit(line, game, fd);
}
