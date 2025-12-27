/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:09:56 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/26 16:41:04 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_linelen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	get_line_nb(char *file_name)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**read_map(char *file_name, t_game *game)
{
	int		fd;
	int		nb_line;
	char	**map;
	int		i;

	i = 0;
	nb_line = get_line_nb(file_name);
	game->map_y = nb_line;
	if (nb_line <= 2)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	while (i <= nb_line)
		map[i++] = get_next_line(fd);
	game->map_x = ft_linelen(map[0]);
	close(fd);
	return (map);
}

void	get_map(char *file_name, t_game *game)
{
	char	**map;

	map = read_map(file_name, game);
	if (!map)
	{
		printf("Error\nUnreadable Map\n");
		(*game).map = NULL;
		return ;
	}
	game->map = map;
}
