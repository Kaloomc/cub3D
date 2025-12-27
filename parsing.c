/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:51:35 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/27 16:09:06 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_path_number(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (0);
	else if (line[0] == 'S' && line[1] == 'O')
		return (1);
	else if (line[0] == 'E' && line[1] == 'A')
		return (2);
	else if (line[0] == 'W' && line[1] == 'E')
		return (3);
	else
		return (-1);
}

int	convert_rgb(char *line)
{
	(void)line;
	return (0);
}

void	get_texture_path(t_game *game, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		game->skip_line_data++;
		if (get_path_number(line) != -1)
			game->paths[get_path_number(line)] = ft_strdup(&line[2]);
		else if (line[0] == 'C')
			game->ceiling_color = convert_rgb(line);
		else if (line[0] == 'F')
			game->floor_color = convert_rgb(line);
		else if (line[0] != '\n')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	parse(t_game *game, char *filename)
{
	get_texture_path(game, filename);
}
