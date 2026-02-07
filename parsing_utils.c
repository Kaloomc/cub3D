/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:47:34 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/07 01:20:18 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_color(char *line, t_game *game)
{
	if (line[0] == 'C')
	{
		game->ceiling_color = convert_rgb(line);
		if (game->ceiling_color == -1)
		{
			printf("Error\nInvalid Ceiling Color\n");
			free(line);
			get_next_line(-1);
			free_mlx(game);
		}
	}
	else if (line[0] == 'F')
	{
		game->floor_color = convert_rgb(line);
		if (game->floor_color == -1)
		{
			printf("Error\nInvalid Floor Color\n");
			free(line);
			get_next_line(-1);
			free_mlx(game);
		}
	}
	return ;
}
