/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:51:35 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/28 16:16:27 by fgarnier         ###   ########.fr       */
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

static int	parse_color_component(char **line)
{
	int	num;

	num = 0;
	while (**line && (**line == ' ' || **line == '\t'))
		(*line)++;
	if (!ft_isdigit(**line))
		return (-1);
	while (**line && ft_isdigit(**line))
	{
		num = num * 10 + (**line - '0');
		(*line)++;
	}
	while (**line && (**line == ' ' || **line == '\t'))
		(*line)++;
	return (num);
}

int	convert_rgb(char *line)
{
	int	r;
	int	g;
	int	b;

	line++;
	r = parse_color_component(&line);
	if (*line == ',')
		line++;
	else
		return (-1);
	g = parse_color_component(&line);
	if (*line == ',')
		line++;
	else
		return (-1);
	b = parse_color_component(&line);
	if (*line != '\n' && *line != '\0')
		return (-1);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

void	get_texture_path(t_game *game, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	line = " ";
	while (line)
	{
		line = get_next_line(fd);
		line = ft_strtrim(line, " ");
		game->skip_line_data++;
		if (get_path_number(line) != -1)
			assign_path(get_path_number(line), line, game);
		else if ((line[0] == 'C') || (line[0] == 'F'))
			get_color(line, game, fd);
		else if (line[0] != '\n')
		{
			free(line);
			break ;
		}
		free(line);
	}
	get_next_line(-1);
	close(fd);
}

void	parse(t_game *game, char *fname)
{
	game->ceiling_color = -1;
	game->floor_color = -1;
	if (ft_strlen(fname) >= 4)
	{
		if (fname[ft_strlen(fname) - 1] == 'b' && fname[ft_strlen(fname)
			- 2] == 'u' && fname[ft_strlen(fname) - 3] == 'c'
			&& fname[ft_strlen(fname) - 4] == '.')
		{
			get_texture_path(game, fname);
			get_map(fname, game);
			init_player_pos(game, 0, 0);
		}
		else
			printf("Error\nFile is not .cub\n");
	}
	else
		printf("Error\nFile is not .cub\n");
}
