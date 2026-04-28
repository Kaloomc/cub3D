/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:14:22 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/28 15:08:10 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map_y + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map_y)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	free_map_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	fill(char **map, int x, int y, int height)
{
	if (y < 0 || y >= height || x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	if (map[y][x] != '0' && !ft_strchr("NSEW", map[y][x]))
		return (0);
	map[y][x] = 'V';
	if (!fill(map, x + 1, y, height))
		return (0);
	if (!fill(map, x - 1, y, height))
		return (0);
	if (!fill(map, x, y + 1, height))
		return (0);
	if (!fill(map, x, y - 1, height))
		return (0);
	return (1);
}

int	check_map_closed(t_game *game)
{
	char	**map_copy;
	int		start_x;
	int		start_y;

	start_x = (int)game->player_x;
	start_y = (int)game->player_y;
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	if (!fill(map_copy, start_x, start_y, game->map_y))
	{
		free_map_copy(map_copy);
		printf("Error\nMap error\n");
		return (0);
	}
	free_map_copy(map_copy);
	return (1);
}
